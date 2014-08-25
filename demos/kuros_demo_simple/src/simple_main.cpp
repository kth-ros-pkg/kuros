#include <iostream>
#include <boost/format.hpp>
#include <boost/thread.hpp>

#include <kuros.h>
#include <HandlingServer.hpp>
#include <DataFile.hpp>



/*

Simplest possible demo.

Send a trajectory to robot,
get and print a stream of responses,
exit when done.

You inherit from Server and implement the
handleResponse() and handleDisconnect() methods.
See HandlingServer.

Trajectory is loaded from a file but could be generated in any way.
Each trajectory needs an info vector with parameters.
You send trajectory directly to robot with
sendTrajectory(info, trajectory).

Trajectory is queued in robot internal buffer.
See/adjust stacksize attribute in Kuros.xml according
to your working methods.

Server only blocks when listening for connection,
then doesn't block once connencted.

If you want to keep connection alive despite errors on the
robot which disconnect it, use the handleDisconnect()
method.

*/

void printTrajectory(const trajectory_vec &trajectory)
{
    cout << "---------------------------------------------" << endl;
    BOOST_FOREACH(const frame_vec &frame, trajectory)
    {
        BOOST_FOREACH(const double &val, frame)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------" << endl;
}


int main()
{

    // load a space-delimited file
    DataFile dataFile;
    std::string filename = "trajectory.txt";

    //vector of frames std::vector< frame_vec >
    trajectory_vec trajectory;  // trajectory vector

    dataFile.loadSDFrames(filename, trajectory);  // store file contents in trajectory vector

    /*
    *****IMPORTANT*****
    Trajectory vector size is used as framecount
    inside the robot, make sure all frames are valid!
    Otherwise robot behaviour will be undefined.
    */
    if (trajectory.empty())
    {
        cerr << "Failed loading trajectory, bailing out!" << endl;
        return 0;
    }

    /*
    Let's print the trajectory.
    */
    cout << "Loaded:" << endl;
    printTrajectory(trajectory);

    // set parameters for trajectory
    info_vec info(KUKA_INFO_SIZE);  // info vectorwith the right size

    /*
    Response modes:

    1   robot sends a response when done with BCO, about to run a trajectory, done with a trajectory, exiting
    3   mode 1 + stream of responses every N ms all the time
    */
    info[KUKA_RMODE]        = KUKA_RMODE_BASIC;     // response mode
    info[KUKA_RMS]          = 100;                  // [ms] response stream interval
    info[KUKA_TRAJID]       = 666;                  // a trajectory id
    info[KUKA_RUN]          = YES;                  // 0 == robot exits after trajectory, 1 == robot keeps running
    info[KUKA_VEL]          = 200;                  // [mm/sec], comfortable vel = 200
    info[KUKA_TOL]          = 20;                   // [mm], max approximation distance from trajectory point
    info[KUKA_FRAMETYPE]    = KUKA_CARTESIAN;       // 1 == cartesian X Y Z Y P R, 2 == joint A1 A2 A3 A4 A5 A6 (not yet supported)

    cout << "Have " << trajectory.size() << " frames to send, starting server." << endl;

    // start server
    HandlingServer aserver;     // loads config file on creation

    aserver.startListening();   // blocks until connection

    /*
    When connected to robot, we arrive here.
    You can also wait for a "ready status" response from robot
    before sending, but here we just wait a little.
    */
    cout << "Waiting a little." << endl;
    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));

    cout << "Sending trajectory with " << trajectory.size() << " frames." << endl;

    // send trajectory previously loaded from file
    aserver.sendTrajectory(info, trajectory);

    // let's make a trajectory with first, last and some other points
    // look how the robot interpolates them
    trajectory_vec pointSampleTrajectory;
    pointSampleTrajectory.push_back(trajectory.front());
    pointSampleTrajectory.push_back(trajectory[10]);
    pointSampleTrajectory.push_back(trajectory[20]);
    pointSampleTrajectory.push_back(trajectory[30]);
    pointSampleTrajectory.push_back(trajectory.back());

    cout << "Sending trajectory with " << pointSampleTrajectory.size() << " frames." << endl;

    // send it, reusing the info vector we already made
    info[KUKA_TRAJID] = 667;
    aserver.sendTrajectory(info, pointSampleTrajectory);

    // lets do the same but send each frame as a separate pose
    // these points won't be interpolated
    trajectory_vec pose;

    cout << "Sending previous poses as separate trajectories." << endl;

    pose.push_back(trajectory.front());
    info[KUKA_TRAJID] = 668;
    aserver.sendTrajectory(info, pose);

    pose[0] = trajectory[10];
    info[KUKA_TRAJID] = 669;
    aserver.sendTrajectory(info, pose);

    pose[0] = trajectory[20];
    info[KUKA_TRAJID] = 670;
    aserver.sendTrajectory(info, pose);

    pose[0] = trajectory[30];
    info[KUKA_TRAJID] = 671;
    aserver.sendTrajectory(info, pose);

    pose[0] = trajectory.back();
    info[KUKA_TRAJID] = 672;
    info[KUKA_RUN] = NO; // for the last trajectory we send Run = 0, robot will exit
    aserver.sendTrajectory(info, pose);


    cout << "Idle." << endl;

    // idle
    while( aserver.isAccepting() ) {

        boost::this_thread::sleep(boost::posix_time::milliseconds(100));
    }

    // we sent Run == 0 so robot exits when done, server disconencts and we quit.
    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    cout << "Done, exiting." << endl;
    return 0;
}

