#include "Server.hpp"

Server::Server()
{
    loadConfig();
}

Server::~Server()
{
    cout << "Server destructor detaching session thread." << endl;
    keepAlive = false; // atomic
    if (session)
    {
        if (session->joinable())
        {
            session->detach();
        }
    }
}

void Server::sendTrajectory(const info_vec &info, const trajectory_vec &trajectory)
{
    if (!accepting)
    {
        cout << "SendTrajectory() can't send because server not connected." << endl;
        return;
    }

    try
    {
        streambuf_ptr message(new boost::asio::streambuf);
        KukaCommand command;
        command.formatTrajectory(*message, info, trajectory);   // first: infovector<int>, second: framevector<int>

        messageQueue.push(message);
    }
    catch (std::exception &e)
    {
        cerr << "responseThread exception: " << e.what() << endl;
    }
}

void Server::loadConfig()
{
    serverConfig.load();
    cout << "Port MaxBufferSize EndString:" << endl;
    serverConfig.printValues();
}

void Server::closeConnection()
{
    //cout << "Server no longer accepting." << endl;
    accepting = false;  // atomic for external use

    //cout << "CloseConnection setting to false." << endl;
    connected = false;  // atomic for internal use

    //cout << "CloseConnection stopping queues." << endl;
    messageQueue.reject();  // stop queues, which should terminate write and response threads
    responseQueue.reject();

    handleDisconnect();     // user can do something
}

void Server::resetData()
{
    // TODO: make these atomic
    invalidParseCount   = 0;
    readMessageCount    = 0;
    writtenMessageCount = 0;
}

void Server::setReconnect(bool onoff)
{
    keepAlive = onoff;  // atomic
}

bool Server::isConnected()
{
    return connected; // atomic
}

void Server::setConnected(bool onoff)
{
    connected = onoff;  // atomic
}


bool Server::isAccepting()
{
    return accepting;   // atomic
}

void Server::responseThread()
{
    //setResponseThreadAlive(true);
    try
    {
        while (connected)
        {
            streambuf_ptr message;
            // Blocks until something is in the queue.
            // If disconnencted it should stop waiting but not touch message pointer, which will be null.
            responseQueue.wait_and_pop(message);

            if (message)
            {
                // we have a message, parse xml and do something
                KukaResponse response;
                response.parse(*message);
                if (response.isValid())     // call user defined handle response only if parser has some success
                {
                    callResponseMethods(response);     // this can be hidden by a derived class
                }
                else
                {
                    ++invalidParseCount;
                    cerr << "Warning! Invalid response, no response handler invoked! Total " << invalidParseCount << " invalid responses received." << endl;
                }
            }
        }

    }
    catch (std::exception &e)
    {
        cerr << "responseThread exception: " << e.what() << endl;
    }

    cout << "Response thread exiting." << endl;
}

void Server::callResponseMethods(const KukaResponse &response)
{
    handleResponse(response);
}

void Server::sleep(int ms)
{
    std::this_thread::sleep_for( std::chrono::milliseconds(ms) );
}

void Server::startListening()
{
    if (session)
    {
        cerr << "Can't start listening. Session already exists, only one session allowed." << endl;
        return;
    }

    accepting = false; // atomic

    try
    {
        // spawn new session thread
        session = thread_ptr(new std::thread(&Server::sessionThread,this,serverConfig.getPort()));
    }
    catch (std::exception &e)
    {
        cerr << "Exception when creating session: " << e.what() << endl;
    }

    // block until connected
    while (!accepting)
    {
        sleep(100);
    }
}

void Server::sessionThread(unsigned short port)
{
    try
    {
        do
        {
            boost::asio::io_service io_service;
            tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));

            cout << "Server listening on port " << port << "." << endl;

            boost::system::error_code acceptError;
            socket_ptr sock(new tcp::socket(io_service));
            acceptor.accept(*sock, acceptError);

            if (acceptError)
            {
                cerr << "Boost error during accept. " << acceptError << endl;
                sleep(1000);
            }
            else
            {
                cout << "A client connected." << endl;

                /*
                If previously connected, threads and socket shall be dead,
                queues and data reset.
                */
                messageQueue.reset();
                responseQueue.reset();
                resetData();            // counters etc

                connected = true;       // atomic

                // spawn
                std::thread read_thread(&Server::readThread,this, sock);
                std::thread write_thread(&Server::writeThread,this, sock);
                std::thread response_thread(&Server::responseThread,this);

                // block for a second to let system get things rolling
                sleep(1000);

                accepting = true;   // finally allow clients to interact, atomic

                read_thread.join();     // calls closeConnection() before exit
                write_thread.join();
                response_thread.join();
            }

            // if we get here, connection is terminated, try to shutdown sockets
            boost::system::error_code shutdownError;
            sock->shutdown(boost::asio::ip::tcp::socket::shutdown_both, shutdownError);    // recommended by boost
            if (shutdownError)
            {
                cerr << "Socket shutdown complains:" << shutdownError << endl;
            }

            boost::system::error_code sockCloseError;
            sock->close(sockCloseError);
            if (sockCloseError)
            {
                cout << "Socket close complains:" << sockCloseError << endl;
            }

            // let socket pointer go out of scope, this should release it

        }
        while (keepAlive);

        cout << "Session thread exiting." << endl;

    }
    catch (std::exception &e)
    {
        cout << "Session exception: " << e.what() << endl;
    }
}

void Server::readThread(socket_ptr sock)
{
    try
    {
        while (connected)
        {

            streambuf_ptr message(new boost::asio::streambuf);

            boost::system::error_code error;
            boost::asio::read_until(*sock, *message, serverConfig.getEndString(), error);   // waits for incoming data or eof

            if (error == boost::asio::error::eof)   // client disconnected
            {
                // signal to all threads
                closeConnection();
                cout << "Client disconnected." << endl;
                //break;
            }
            else if (error)
            {
                cerr << "Boost error while reading: " << error << endl;
            }
            else
            {
                responseQueue.push(message);
                ++readMessageCount;
            }

        }
    }
    catch (std::exception &e)     // complain but don't quit
    {
        cerr << "Read thread exception: " << e.what() << endl;
    }

    cout << "Read thread exiting." << endl;
}

void Server::writeThread(socket_ptr sock)
{
    try
    {
        while (connected)
        {
            /*
            Wait until something in queue.
            If disconnected it should stop waiting without touching message pointer.
            */
            streambuf_ptr message;
            messageQueue.wait_and_pop(message);

            if (message)
            {
                boost::system::error_code error;
                boost::asio::write(*sock, *message, error);
                if (error)
                {
                    cerr << "Boost error while writing: " << error << endl;
                }
                else
                {
                    ++writtenMessageCount;
                }
            }
        }
    }
    catch (std::exception &e)
    {
        cerr << "Writing exception: " << e.what() << endl;
    }

    cout << "Write thread exiting." << endl;
};

/*
Returns a pointer to buffer inside streambuf.
*/
const char * Server::streambufToPtr(boost::asio::streambuf &message)
{
    const char* bufPtr=boost::asio::buffer_cast<const char*>(message.data());
    return bufPtr;
}

