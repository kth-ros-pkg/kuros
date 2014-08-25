#include "ros/ros.h"
#include "kurosp/SendTrajectory.h"

#include <iostream>

#include "kuros_constants.hpp"    // to get access to KUKA constants

using std::cout;
using std::endl;

typedef boost::array<double, 6ul> corr_vec; // matches ROS definition
typedef boost::array<double, 6ul> pose_vec;

/** A correction based control method using the send_trajectory service
    together with one of the kurostream KRL programs on the robot.
    */

/** WARNING!
    Make sure robot has stopped BEFORE quitting this program,
    shutting down ROS, crashing the computer etc.
    Otherwise the latest correction might be active
    and robot will keep moving until it hits something.
    */


int main(int argc, char **argv)
{
    ros::init(argc, argv, "send_stream_testclient");

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<kurosp::SendTrajectory>("send_trajectory");

    kurosp::SendTrajectory srv;

    // make a zeroed ros message
    kurosp::XyzYpr frame;
    for (int i = 0; i < KUKA_FRAME_SIZE; ++i)
    {
        frame.xyzypr[i] = 0;
    }
    srv.request.trajectory.frames.push_back(frame);


    // define info for the trajectory
    srv.request.trajectory.info.response_mode = KUKA_RMODE_BASIC;
    srv.request.trajectory.info.response_ms = 100;
    srv.request.trajectory.info.traj_id = 666;
    srv.request.trajectory.info.run = YES;
    srv.request.trajectory.info.vel = 200;
    srv.request.trajectory.info.tol = 20;
    srv.request.trajectory.info.frame_type = KUKA_CARTESIAN_REL;

    // stepsize
    double step = 0.5; // [mm]

    // make vectors with simple corrections
    corr_vec down       = {0,0,-step,0,0,0};
    corr_vec up         = {0,0,step,0,0,0};
    corr_vec dontmove   = {0,0,0,0,0,0};
    corr_vec left       = {0,-step,0,0,0,0};
    corr_vec right      = {0,step,0,0,0,0};
    corr_vec towall     = {-step,0,0,0,0,0};
    corr_vec fromwall   = {step,0,0,0,0,0};


    // make a vector with command strings to print in console
    std::vector<std::string> com; // {"stop", "down", "up", "left", "right", "to wall", "from wall" };
    com.push_back("stop");
    com.push_back("down");
    com.push_back("up");
    com.push_back("left");
    com.push_back("right");
    com.push_back("to wall");
    com.push_back("from wall");

    // make a vector with the corrections so we can toggle between them
    std::vector<corr_vec> corrections; // {dontmove, down, up, left, right, towall, fromwall};
    corrections.push_back(dontmove);
    corrections.push_back(down);
    corrections.push_back(up);
    corrections.push_back(left);
    corrections.push_back(right);
    corrections.push_back(towall);
    corrections.push_back(fromwall);

    // make a vector with absolute home position
    pose_vec home = {0, 530, 730, -90, 45, 180};

    // make a vector with ansolute starting position
    pose_vec startpose = {100, 530, 630, -90, 45, 180};

    int corrsize = boost::lexical_cast<int>(corrections.size());
    int counter = 0;
    int maxCorrections = 10;

    cout << "WARNING! Make sure robot stopped when quitting this node!" << endl;

    cout << "Sending absolute start pose and waiting 5s." << endl;

    srv.request.trajectory.info.frame_type = KUKA_CARTESIAN;    // absolute cartesian
    srv.request.trajectory.frames[0].xyzypr = startpose;

    // call the service and send
    if (client.call(srv))
    {
        if (srv.response.success)
        {
            ROS_INFO("Sent absolute starting pose.");
        }
        else
        {
            ROS_INFO("Server not accepting, is robot connected? Exiting.");
            return 0;
        }
    }
    else
    {
        ROS_ERROR("Failed to call service send_trajectory");
        return 1;
    }

    ros::Duration(5).sleep();

    cout << "Starting to send corrections with stepsize " << step << " mm." << endl;

    srv.request.trajectory.info.frame_type = KUKA_CARTESIAN_REL;    // relative cartesian

    while (ros::ok() && counter < maxCorrections)   // send some relative corrections
    {
        ros::Duration(1).sleep();

        int next = counter % corrsize;

        // set correction
        srv.request.trajectory.frames[0].xyzypr = corrections[next];

        // call the service and send
        if (client.call(srv))
        {
            if (srv.response.success)
            {
                ROS_INFO("%s", com[next].c_str());
                ++counter;
            }
            else
            {
                ROS_INFO("Server not accepting, is robot connected?");
                // don't increment counter, we send same correction next loop
            }
        }
        else
        {
            ROS_ERROR("Failed to call service send_trajectory");
            return 1;
        }
    }



    cout << "Sending absolute home pose." << endl;

    srv.request.trajectory.info.frame_type = KUKA_CARTESIAN;    // absolute cartesian
    srv.request.trajectory.frames[0].xyzypr = home;

    if (client.call(srv))
    {
        if (srv.response.success)
        {
            ROS_INFO("Sent absolute home pose.");
        }
        else
        {
            ROS_INFO("Server not accepting, is robot connected? Exiting.");
            return 0;
        }
    }
    else
    {
        ROS_ERROR("Failed to call service send_trajectory");
        return 1;
    }

    return 0;
}
