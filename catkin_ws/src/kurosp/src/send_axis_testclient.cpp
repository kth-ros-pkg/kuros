#include "ros/ros.h"
#include "kurosp/SendTrajectory.h"

#include "kuros_constants.hpp"    // to get access to KUKA constants

typedef std::vector<double> frame_vec;

/** This sends AXIS A1-A6 angles instead of cartesian coords.
    By setting frame_type to KUKA_AXIS the KRL program
    on the robot executes interpolated PTP motion instead.
    */

int main(int argc, char **argv)
{
    ros::init(argc, argv, "send_axis_testclient");

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<kurosp::SendTrajectory>("send_trajectory");

    kurosp::SendTrajectory srv;

    // define a trajectory with some poses in axis angles
    int posecount = 12;
    double poses[][KUKA_FRAME_SIZE] =
    {
        {-90, -91, 91, 0, 0, 0,     },
        {-90, -91, 91, 0, 45, 0,    },
        {-90, -91, 91, 0, 45, 45,   },
        {-90, -91, 91, 0, 45, 0,    },
        {-90, -91, 91, 20, 45, 0,   },
        {-90, -91, 91, 0, 45, 0,    },
        {-90, -91, 80, 0, 45, 0,    },
        {-90, -91, 91, 0, 45, 0,    },
        {-90, -81, 91, 0, 45, 0,    },
        {-90, -91, 91, 0, 45, 0,    },
        {-80, -91, 91, 0, 45, 0,    },
        {-90, -91, 91, 0, 45, 0     }
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

    /** WARNING! Be very careful setting velocity in AXIS mode.
    Velocity in AXIS mode is interpreted as (maxAxisVelocity * 0.01)
    so 500 gives 5% of maximum, which is already fast enough.
    A value of 2000 (20%) is BRUTAL!
    */
    srv.request.trajectory.info.vel = 500; // [1/100 percent] in AXIS mode

    srv.request.trajectory.info.tol = 20;
    srv.request.trajectory.info.frame_type = KUKA_AXIS; // this sets PTP axis

    // call the service and send
    if (client.call(srv))
    {
        if (srv.response.success)
        {
            ROS_INFO("Axis trajectory sent.");
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
