#include <iostream>
#include <thread>
#include <kuros.h>

#include <HandlingServer.hpp>


void sleep(const int ms)
{
    std::this_thread::sleep_for( std::chrono::milliseconds(ms) );
}

int main()
{
    HandlingServer aserver;
    aserver.startListening();   // blocks until connection

    // make an info vector
    info_vec info
    {
        KUKA_RMODE_STREAM,      // response mode
        100,                    // [ms] response stream interval
        0,                      // a trajectory id
        YES,                    // NO robot exits after trajectory, YES robot keeps running
        200,                    // [mm/sec], comfortable vel = 200
        20,                     // [mm*0.01], max approximation distance from trajectory point
        KUKA_CARTESIAN          // we will use KUKA_CARTESIAN and KUKA_CARTESIAN_REL
    };

    double step = 0.5;    // [mm]   the stepsize in space

    frame_vec down {0,0,-step,0,0,0};
    frame_vec up {0,0,step,0,0,0};
    frame_vec dontmove {0,0,0,0,0,0};
    frame_vec left {0,-step,0,0,0,0};
    frame_vec right {0,step,0,0,0,0};
    frame_vec towall {-step,0,0,0,0,0};
    frame_vec fromwall {step,0,0,0,0,0};

    std::vector<std::string> com {"stop", "down", "up", "left", "right", "to wall", "from wall" };

    // we use this to toggle between corrections
    std::vector<frame_vec> corrections {dontmove, down, up, left, right, towall, fromwall};

    // make a vector with absolute home position
    frame_vec home {0, 530, 730, -90, 45, 180};

    // make a vector with ansolute starting position
    frame_vec startpose {100, 530, 630, -90, 45, 180};

    int corrsize = boost::lexical_cast<int>(corrections.size());
    int counter = 0;

    cout << "WARNING! Make sure robot stopped when quitting this program!" << endl;

    cout << "Sending absolute start pose and waiting 5s." << endl;

    info[KUKA_FRAMETYPE] = KUKA_CARTESIAN;    // absolute cartesian
    aserver.sendTrajectory(info, trajectory_vec{startpose});

    sleep(5000);

    cout << "Starting to send corrections with stepsize " << step << " mm." << endl;

    info[KUKA_FRAMETYPE] = KUKA_CARTESIAN_REL;    // set relative cartesian for all corrections

    while (counter < 10)
    {
        // every n seconds, change direction
        sleep(1000);

        int next = counter % corrsize;

        aserver.sendTrajectory(info, trajectory_vec{corrections[next]} );   // "doCorrect()"
        cout <<  com[next] << endl;

        ++counter;
    }

    cout << "ending robot home." << endl;

    // send robot home
    info[KUKA_FRAMETYPE] = KUKA_CARTESIAN;    // absolute cartesian
    aserver.sendTrajectory(info, trajectory_vec{home});

    // don't exit immediately or server will be destroyed
    sleep(1000);

    cout << "Main thread exiting." << endl;
    return 0;

}
