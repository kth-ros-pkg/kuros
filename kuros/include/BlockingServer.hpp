#ifndef BLOCKINGSERVER_HPP
#define BLOCKINGSERVER_HPP

#include <Server.hpp>


//#include <boost/thread.hpp>

//#include <mutex>

class BlockingServer : public Server
{

public:
    BlockingServer();
    virtual ~BlockingServer();

    void blockSendTrajectory(const info_vec &info, const trajectory_vec &trajectory);

protected:

    /*
    Also breaks send block on disconnect.
    */
    void closeConnection(); // override;

private:

    bool trajectoryPending;
    boost::condition_variable sendBlockCondition;
    boost::mutex sendBlockMutex;
    //mutable std::mutex sendBlockMutex;
    //std::condition_variable sendBlockCondition;

    //int robotState = 0;

    void callResponseMethods(const KukaResponse &response); // override;

    void trajectoryDone(const KukaResponse &response);

    void setPending(bool onoff);
    bool isPending();
    void blockWhilePending();

};

#endif // BLOCKINGSERVER_HPP
