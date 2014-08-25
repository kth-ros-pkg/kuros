#include <iostream>
#include <boost/format.hpp>
#include <boost/thread.hpp>

#include <kuros.h>
#include <HandlingServer.hpp>


/*
Demo of blocking send.
Also shows how to make trajectories by hand.
*/
int main()

{
    // an info vector with correct amount of ints
    info_vec info(KUKA_INFO_SIZE);

    // set trajectory parameters in the info vector
    info[KUKA_RMODE]        = KUKA_RMODE_BASIC;     // response mode
    info[KUKA_RMS]          = 100;                  // [ms] response stream interval
    info[KUKA_TRAJID]       = 0;                    // a trajectory id
    info[KUKA_RUN]          = YES;                  // NO robot exits after trajectory, YES robot keeps running
    info[KUKA_VEL]          = 200;                  // [mm/sec], comfortable vel = 200
    info[KUKA_TOL]          = 20;                   // [mm], max approximation distance from trajectory point
    info[KUKA_FRAMETYPE]    = KUKA_CARTESIAN;       // KUKA_CARTESIAN X Y Z Y P R, KUKA_AXIS A1 A2 A3 A4 A5 A6 (not yet supported)


    /*
    This time HandlingServer inherits from BlockingServer
    which gives access to blockSendTrajectory().
    Same idea, you must implement
    handleResponse(const KukaResponse &response) and handleDisconnect()
    even if they do nothing special. Look in class definition.
    */
    HandlingServer aserver;
    aserver.startListening();   // blocks until connection

    cout << "Waiting a little." << endl;
    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));


    while (aserver.isAccepting())
    {
        // Lets keep sending trajectories over and over until user quits

        // ------------------------------------------------------------------------------------

        /*
        A frame_vec is std::vector<double>.
        A trajectory_vec is std::vector<frame_vec>.
        Use your favourite method to get coordinates into a frame_vec, which you then put into your trajectory_vec.
        Make sure frames and trajectories are valid, otherwise lord knows what will happen.
        */

        // this is the KTH home position, we will use it a couple times
        const double homearr[KUKA_FRAME_SIZE] = {0, 530, 730, -90, 45, 180};
        frame_vec homepos (homearr, homearr + KUKA_FRAME_SIZE );

        // empty trajectory vector
        trajectory_vec trajectory;

        // create and append a point
        frame_vec apoint(KUKA_FRAME_SIZE);
        apoint[KUKA_FRAME_X] = 86.603;
        apoint[KUKA_FRAME_Y] = 650;
        apoint[KUKA_FRAME_Z] = 555.56;
        apoint[KUKA_FRAME_A] = -90;
        apoint[KUKA_FRAME_B] = 0;
        apoint[KUKA_FRAME_C] = 180;
        trajectory.push_back(apoint);

        // another point from array using frame_vec assign constructor
        double anarray[KUKA_FRAME_SIZE] = {50, 513.4, 605.56, -90, 0, 180};
        trajectory.push_back(frame_vec(anarray, anarray+KUKA_FRAME_SIZE));

        // third point reusing array
        anarray[KUKA_FRAME_X] = -100;
        anarray[KUKA_FRAME_Y] = 600;
        anarray[KUKA_FRAME_Z] = 650;
        anarray[KUKA_FRAME_A] = -90;
        anarray[KUKA_FRAME_B] = 0;
        anarray[KUKA_FRAME_C] = 180;
        trajectory.push_back(frame_vec(anarray, anarray+KUKA_FRAME_SIZE));

        // final point - back home
        trajectory.push_back(homepos);

        // let's set trajectory id
        info[KUKA_TRAJID] = 666;

        cout << "Sending (blocking)  trajectory with " << trajectory.size() << " frames." << endl;

        /*

        blockSendTrajectory() will block when:

            sent a trajectory       - waits for response with status 4 (KUKA_TRAJ_DONE)

        blockSendTrajectory() will return without sending anything when server not connected.

        */
        aserver.blockSendTrajectory(info, trajectory);  // ***SENDING*** and blocking

        cout << "blockSendTrajectory returned, trajectory done, continue." << endl;

        // Let's send another trajectory (a single pose) ------------------------------------------------------------------------------------

        ++info[KUKA_TRAJID];

        trajectory_vec pose;
        anarray[KUKA_FRAME_X] = 50;
        anarray[KUKA_FRAME_Y] = 686.6;
        anarray[KUKA_FRAME_Z] = 694.44;
        anarray[KUKA_FRAME_A] = -90;
        anarray[KUKA_FRAME_B] = 0;
        anarray[KUKA_FRAME_C] = 180;
        pose.push_back(frame_vec(anarray, anarray+KUKA_FRAME_SIZE));

        cout << "Sending (blocking)  pose with " << pose.size() << " frames." << endl;
        aserver.blockSendTrajectory(info, pose);
        cout << "blockSendTrajectory returned, pose continue." << endl;

        // Let's send another trajectory (home) ------------------------------------------------------------------------------------

        ++info[KUKA_TRAJID];

        pose[0] = homepos;  // reuse previous trajectory

        cout << "Sending (blocking)  pose with " << pose.size() << " frames." << endl;
        aserver.blockSendTrajectory(info, pose);
        cout << "blockSendTrajectory returned, continue." << endl;

        // ------------------------------------------------------------------------------------

        cout << "Done. Looping. -------------------------------" << endl;
    }

    cout << "Loop ended because server no longer connected." << endl;

    boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
    cout << "Main thread exiting." << endl;

    return 0;
}

//int main()
//{
//    // Lets keep sending trajectories over and over until user quits or robot disconnects
//
//    // ------------------------------------------------------------------------------------
//
//    // this is the KTH home position, we will use it a couple times
//    frame_vec homepos {0, 530, 730, -90, 45, 180};
//
//    /*
//    A frame_vec is std::vector<double>.
//    A trajectory_vec is std::vector<frame_vec>.
//    Use your favourite method to get coordinates into a frame_vec, which you then put into your trajectory_vec.
//    Make sure frames and trajectories are valid, otherwise lord knows what will happen.
//    */
//
//    // empty trajectory vector
//    trajectory_vec trajectory;
//
//    // append a point
//    trajectory.push_back(frame_vec {86.603, 650, 555.56, -90, 0, 180});
//
//    // another point from array using frame_vec assign constructor
//    double anarray[KUKA_FRAME_SIZE] = {50, 513.4, 605.56, -90, 0, 180};
//    trajectory.emplace_back(anarray, anarray+KUKA_FRAME_SIZE);
//
//    // third point using frame_vec assign constructor and iterator
//    frame_vec apoint {-100, 600, 650, -90, 0, 180};
//    trajectory.emplace_back(apoint.begin(),apoint.end());
//
//    // final point - back home
//    trajectory.push_back(homepos);
//
//    cout << "-----------------------------------------------------" << endl;
//    cout << "Printing trajectory with " << trajectory.size() << " frames." << endl;
//
//    for (auto frame: trajectory)
//    {
//        for (auto val: frame )
//        {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "-----------------------------------------------------" << endl;
//
//    // Let's send another trajectory (a single pose) ------------------------------------------------------------------------------------
//
//    trajectory_vec pose;
//    pose.emplace_back(frame_vec {50, 686.6, 694.44, -90, 0, 180});
//
//    cout << "-----------------------------------------------------" << endl;
//    cout << "Printing pose with " << pose.size() << " frames." << endl;
//
//    for (auto frame: pose)
//    {
//        for (auto val: frame )
//        {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "-----------------------------------------------------" << endl;
//
//    // Let's send another trajectory (home) ------------------------------------------------------------------------------------
//
//    pose[0] = homepos;  // reuse previous trajectory
//
//    cout << "-----------------------------------------------------" << endl;
//    cout << "Printing pose with " << pose.size() << " frames." << endl;
//
//    for (auto frame: pose)
//    {
//        for (auto val: frame )
//        {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "-----------------------------------------------------" << endl;
//
//    return 0;
//
//}
