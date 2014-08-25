#ifndef BLOCKINGHANDLINGSERVER_HPP_INCLUDED
#define BLOCKINGHANDLINGSERVER_HPP_INCLUDED

#include "kuros.h"

#include "ros/ros.h"
#include "kurosp/SendTrajectory.h"

#include "sensor_msgs/JointState.h"
#include "kurosp/XyzYprState.h"

//#include <boost/shared_ptr.hpp>

class BlockingHandlingServer : public BlockingServer
{
    public:
        BlockingHandlingServer();
        virtual ~BlockingHandlingServer();

        /*
        Handles incoming messages from robot.
        We have access to response object in server and its members:

        response.info   // std::vec<int> [KUKA_RSP_INFO_SIZE]
        response.frame  // std::vec<double> [KUKA_FRAME_SIZE]
        response.axis   // std::vec<double> [KUKA_AXIS_SIZE]

        */
        void handleResponse(const KukaResponse &response);  // override
        void handleDisconnect();    // override

        void createPublishers(ros::NodeHandle &n);

    protected:
    private:

        ros::Publisher carState;
        ros::Publisher jointState;
        int handledCount;
};


#endif // BLOCKINGHANDLINGSERVER_HPP_INCLUDED
