#include "ros/ros.h"
#include "kurosp/SendTrajectory.h"

#include "kuros_constants.hpp"    // to get access to KUKA constants

typedef std::vector<double> frame_vec;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "send_trajectory_testclient");

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<kurosp::SendTrajectory>("send_trajectory");

    kurosp::SendTrajectory srv;

    // define a trajectory with some poses
    int posecount = 4;
    double poses[][KUKA_FRAME_SIZE] =
    {
        {86.603, 650, 555.56, -90, 0, 180,      },
        {86.603, 550, 611.11, -90, 0, 180,      },
        {-2.4499e-13, 500, 666.67, -90, 0, 180, },
        {0, 530, 730, -90, 45, 180              }
    };

    // load into ros message
    kurosp::XyzYpr frame;
    for (int i = 0; i < posecount; ++i)
    {
        for (int j = 0; j < KUKA_FRAME_SIZE; ++j)
        {
            frame.xyzypr[j] = poses[i][j];
        }

        srv.request.trajectory.frames.push_back(frame);
    }

    // define info for the trajectory
    srv.request.trajectory.info.response_mode = KUKA_RMODE_STREAM;
    srv.request.trajectory.info.response_ms = 100;
    srv.request.trajectory.info.traj_id = 666;
    srv.request.trajectory.info.run = YES;
    srv.request.trajectory.info.vel = 200;
    srv.request.trajectory.info.tol = 20;
    srv.request.trajectory.info.frame_type = KUKA_CARTESIAN;

    // call the service and send
    if (client.call(srv))
    {
        if (srv.response.success)
        {
            ROS_INFO("Trajectory sent.");
        }
        else
        {
            ROS_INFO("Server not accepting, is robot connected?");
        }
    }
    else
    {
        ROS_ERROR("Failed to call service send_trajectory");
        return 1;
    }

    return 0;
}
