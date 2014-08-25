#include "BlockingServer.hpp"

BlockingServer::BlockingServer()
{
    //ctor
}

BlockingServer::~BlockingServer()
{
    //dtor
}

void BlockingServer::blockSendTrajectory(const info_vec &info, const trajectory_vec &trajectory)
{
    if (!isAccepting())
    {
        cerr << "blockSendTrajectory() can't send because server not connected." << endl;
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
        cerr << "BlockSendTrajectory exception: " << e.what() << endl;
    }

    // block until trajectoryPending is false again.
    setPending(true);
    blockWhilePending();
}

void BlockingServer::blockWhilePending()
{
    std::unique_lock<std::mutex> lk(sendBlockMutex);
    sendBlockCondition.wait(lk,[this] {return !trajectoryPending;});
}

void BlockingServer::setPending(bool onoff)
{
    //boost::lock_guard<boost::mutex> lock(sendBlockMutex);
    std::lock_guard<std::mutex> lk(sendBlockMutex);
    trajectoryPending=onoff;
}

bool BlockingServer::isPending()
{
    //boost::lock_guard<boost::mutex> lock(sendBlockMutex);
    std::lock_guard<std::mutex> lk(sendBlockMutex);
    return trajectoryPending;
}

void BlockingServer::callResponseMethods(const KukaResponse &response)
{
    // user response
    handleResponse(response);   // lets call this before trajectory unblocks

    // if finished with a pending trajectory, unblock send thread
    trajectoryDone(response);
}


void BlockingServer::trajectoryDone(const KukaResponse &response)
{

    //if (isPending() && response.info[KUKA_RSP_STATUS]==KUKA_TRAJ_DONE)  // TODO: do we need the ispending?
    if (response.info[KUKA_RSP_STATUS]==KUKA_TRAJ_DONE)
    {
        setPending(false);
        sendBlockCondition.notify_one();
    }

}

void BlockingServer::closeConnection()
{
    Server::closeConnection();

    setPending(false);
    sendBlockCondition.notify_one();
}
