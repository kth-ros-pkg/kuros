#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <mutex>
#include <atomic>
#include <thread>

#include <boost/asio.hpp>
//#include <boost/thread.hpp>

#include <types.hpp>

#include <ThreadSafeQueue.hpp>

#include <ServerConfig.hpp>
#include <KukaResponse.hpp>
#include <KukaCommand.hpp>

using boost::asio::ip::tcp;
//using boost::thread;

// ---------------------------------------------------------------------------
// Types used by server
// ---------------------------------------------------------------------------

typedef std::shared_ptr<tcp::socket> socket_ptr;
typedef std::shared_ptr<boost::asio::streambuf> streambuf_ptr;
typedef std::shared_ptr<std::thread> thread_ptr;
typedef std::shared_ptr<ThreadSafeQueue<streambuf_ptr>> queue_ptr;

// ---------------------------------------------------------------------------
// Class
// ---------------------------------------------------------------------------

class Server
{
public:

    // ---------------------------------------------------------------------------
    // Constructor / Destructor
    // ---------------------------------------------------------------------------

    Server();

    virtual ~Server();

    // ---------------------------------------------------------------------------
    // Pure Virtual
    // ---------------------------------------------------------------------------

    /*
    handleResponse() is called from a separate response thread.
    There is a queue between the socket and this call. Still, handleResponse()
    blocks the thread until return. If you expect a 12ms stream of responses,
    it's probably a good idea to deal with the response swiftly.
    */
    virtual void handleResponse(const KukaResponse &response) = 0; // This is mandatory to implement in derived class
    virtual void handleDisconnect() = 0; // This is mandatory to implement in derived class

    // ---------------------------------------------------------------------------
    // Methods
    // ---------------------------------------------------------------------------

    // void sendPose(const info_vec &info, const frame_vec &frame); // deprecated

    void sendTrajectory(const info_vec &info, const trajectory_vec &trajectory);

    virtual void startListening();  // can be overridden

    void setReconnect(bool onoff);

    void loadConfig();

    bool isAccepting();

protected:

    ThreadSafeQueue<streambuf_ptr> messageQueue;    // TODO: make threadsafe queue pointers here instead
    ThreadSafeQueue<streambuf_ptr> responseQueue;   // TODO: create and destroy queues inside session

    virtual void closeConnection();

private:

    // ---------------------------------------------------------------------------
    // Data
    // ---------------------------------------------------------------------------

    //bool connected = false;         // Breaks read,write and responseThread while loops.
    std::atomic<bool> connected {false};

    bool isConnected();
    void setConnected(bool onoff);

    std::atomic<bool> accepting {false};    // for external queries, is it accepting sends?
    std::atomic<bool> keepAlive {false};    // after connecting once and disconnecting, will we connect again?


    std::atomic<int> invalidParseCount {0};      // handy counters
    std::atomic<int> readMessageCount {0};
    std::atomic<int> writtenMessageCount {0};

    void resetData();

    // pointer to the sesson thread
    thread_ptr session;

    // XML parsers
    ServerConfig serverConfig;

    // ---------------------------------------------------------------------------
    // Private Methods
    // ---------------------------------------------------------------------------

    void responseThread();

    /*
    To be overridden by a derived class.
    Provides a way for server to take internal action
    on responses, in addition to calling handleResponse().
    */
    virtual void callResponseMethods(const KukaResponse &response);

    /*
    Specify socket pointer.
    Blocks until connection ends.
    */
    void readThread(socket_ptr sock);

    /*
    Specify socket pointer.
    Blocks until connection ends.
    */
    void writeThread(socket_ptr sock);

    void sessionThread(unsigned short port);

    void sleep(int ms);

    /*
    Returns a pointer to buffer inside streambuf.
    */
    const char * streambufToPtr(boost::asio::streambuf &message);



};

#endif // SERVER_H

