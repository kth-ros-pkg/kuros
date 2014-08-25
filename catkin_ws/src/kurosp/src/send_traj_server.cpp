#include "ros/ros.h"
#include "kurosp/SendTrajectory.h"

#include "sensor_msgs/JointState.h"

#include "kuros.h"
#include "HandlingServer.hpp"

// create server and load ServerConfig.xml
HandlingServer kserver;

/*
If you want, print the incoming trajectory to console.
*/
void printTrajectory(const info_vec &info, const trajectory_vec &trajectory)
{
    ROS_INFO("============================");
    ROS_INFO("info: %d %d %d %d %d %d %d",
             info[KUKA_RMODE],
             info[KUKA_RMS],
             info[KUKA_TRAJID],
             info[KUKA_RUN],
             info[KUKA_VEL],
             info[KUKA_TOL],
             info[KUKA_FRAMETYPE]
            );
    ROS_INFO("----------------------------");
    for (size_t i = 0; i < trajectory.size(); ++i )
    {
        frame_vec frame = trajectory[i];
        ROS_INFO("frame: %f %f %f %f %f %f",
             frame[0],
             frame[1],
             frame[2],
             frame[3],
             frame[4],
             frame[5]
            );
    }
    ROS_INFO("============================");
}

/**
Copy incoming values and send them to robot.
*/
bool sendService(kurosp::SendTrajectory::Request &req,
                 kurosp::SendTrajectory::Response &res)
{
    if (!kserver.isAccepting()) // don't send if server is not connected to robot
    {
        res.success = false;
        return true;
    }

    // empty trajectory vector
    trajectory_vec trajectory;

    // copy the frames
    int trajSize = req.trajectory.frames.size();

    for (int i = 0; i < trajSize; ++i)
    {
        frame_vec frame(KUKA_FRAME_SIZE);

        frame[KUKA_FRAME_X] = req.trajectory.frames[i].xyzypr[KUKA_FRAME_X];
        frame[KUKA_FRAME_Y] = req.trajectory.frames[i].xyzypr[KUKA_FRAME_Y];
        frame[KUKA_FRAME_Z] = req.trajectory.frames[i].xyzypr[KUKA_FRAME_Z];
        frame[KUKA_FRAME_A] = req.trajectory.frames[i].xyzypr[KUKA_FRAME_A];
        frame[KUKA_FRAME_B] = req.trajectory.frames[i].xyzypr[KUKA_FRAME_B];
        frame[KUKA_FRAME_C] = req.trajectory.frames[i].xyzypr[KUKA_FRAME_C];

        trajectory.push_back(frame);
    }

    // copy the info
    info_vec info(KUKA_INFO_SIZE);
    info[KUKA_RMODE] = req.trajectory.info.response_mode;
    info[KUKA_RMS] = req.trajectory.info.response_ms;
    info[KUKA_TRAJID] = req.trajectory.info.traj_id;
    info[KUKA_RUN] = req.trajectory.info.run;
    info[KUKA_VEL] = req.trajectory.info.vel;
    info[KUKA_TOL] = req.trajectory.info.tol;
    info[KUKA_FRAMETYPE] = req.trajectory.info.frame_type;

    // non-blocking send
    kserver.sendTrajectory(info, trajectory);

//    cout << "Printing trajectory." << endl;
//    printTrajectory(info, trajectory);

    res.success = true;
    return true;
}

int main(int argc, char **argv)
{
    // init ROS
    ros::init(argc, argv, "send_trajectory_server");
    ros::NodeHandle n;

    // advertise service
    ros::ServiceServer service = n.advertiseService("send_trajectory", sendService);

    // the publisher are stored in the server so you need to create them before
    kserver.createPublishers(n);

    // start the server
    kserver.setReconnect(true); // if connection breaks, start listening again
    kserver.startListening();

    ROS_INFO("Ready to send trajectory to Kuka.");

    ros::spin();

    return 0;
}

