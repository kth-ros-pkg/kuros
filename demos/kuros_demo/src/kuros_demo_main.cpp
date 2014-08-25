#include <iostream>
#include <thread>

#include <HandlingServer.hpp>   // implemented by user

int main()
{

    // start server
    HandlingServer aserver;     // loads config file on creation

    // connect
    aserver.startListening();   // blocks until connection

    // from now on the HandlingServer deals with the robot.

    // idle until server disconnects
    while(aserver.isAccepting())
    {

        std::this_thread::sleep_for( std::chrono::milliseconds(100) );
    }

    return 0;
}
