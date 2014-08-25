#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
//#include <mutex>
//#include <atomic>
//#include <thread>

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/atomic.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <types.hpp>

#include <ThreadSafeQueue03.hpp>

#include <ServerConfig.hpp>
#include <KukaResponse.hpp>
#include <KukaCommand.hpp>

using boost::asio::ip::tcp;
using boost::thread;

// ---------------------------------------------------------------------------
// Types used by server
// ---------------------------------------------------------------------------

typedef boost::shared_ptr<tcp::socket> socket_ptr;
typedef boost::shared_ptr<boost::asio::streambuf> streambuf_ptr;
typedef boost::shared_ptr<boost::thread> thread_ptr;
typedef boost::shared_ptr<ThreadSafeQueue03<streambuf_ptr> > queue_ptr;

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

    ThreadSafeQueue03<streambuf_ptr> messageQueue;    // TODO: make threadsafe queue pointers here instead
    ThreadSafeQueue03<streambuf_ptr> responseQueue;   // TODO: create and destroy queues inside session

    virtual void closeConnection();

private:

    // ---------------------------------------------------------------------------
    // Data
    // ---------------------------------------------------------------------------

    //bool connected = false;         // Breaks read,write and responseThread while loops.
    boost::atomic<bool> connected;

    bool isConnected();
    void setConnected(bool onoff);

    boost::atomic<bool> accepting;    // for external queries, is it accepting sends?
    boost::atomic<bool> keepAlive;    // after connecting once and disconnecting, will we connect again?


    boost::atomic<int> invalidParseCount;      // handy counters
    boost::atomic<int> readMessageCount;
    boost::atomic<int> writtenMessageCount;

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

