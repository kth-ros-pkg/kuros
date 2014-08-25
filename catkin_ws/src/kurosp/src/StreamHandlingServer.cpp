#include "StreamHandlingServer.hpp"

StreamHandlingServer::StreamHandlingServer() :
    handledCount(0)
{

}

StreamHandlingServer::~StreamHandlingServer()
{
    //dtor
}

void StreamHandlingServer::handleResponse(const KukaResponse &response)
{

    kurosp::XyzYprState carMsg;

    carMsg.status = response.info[KUKA_RSP_STATUS];
    carMsg.id = response.info[KUKA_RSP_TRAJID];
    carMsg.tick = response.info[KUKA_RSP_TICK];

    for (size_t i = 0; i < response.frame.size(); ++i)
    {
        carMsg.xyzypr[i] = response.frame[i];
    }

    carState.publish(carMsg);

    sensor_msgs::JointState jsMsg;

    for (size_t i = 0; i < response.axis.size(); ++i)
    {
        jsMsg.position.push_back(response.axis[i]);
    }

    jointState.publish(jsMsg);

    ++handledCount;
}

void StreamHandlingServer::handleDisconnect()
{
//    cout << "------------------------------------------------" << endl;
//    cout << "HandlingServer: Ending session." << endl;
//    cout << "------------------------------------------------" << endl;
}

void StreamHandlingServer::createPublishers(ros::NodeHandle &n)
{
    carState = n.advertise<kurosp::XyzYprState>("kuka_cartesian_state", 1000);
    jointState = n.advertise<sensor_msgs::JointState>("kuka_joint_state", 1000);
}
