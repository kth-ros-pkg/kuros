#include "HandlingServer.hpp"

HandlingServer::HandlingServer()
{
    //ctor
}

HandlingServer::~HandlingServer()
{
    //dtor
}

/*
Here we use the callback to capture data.
Capturing onof is set from main thread.
*/
void HandlingServer::handleResponse(const KukaResponse &response)
{

    ++handledCount;

//    switch (response.info[KUKA_RSP_STATUS])
//    {
//    case KUKA_NOSTATUS: // not connected or exiting
//        cout << "Robot offline.\n";
//        printResponse(response);
//
//        break;
//
//    case KUKA_READY: // BCO completed, ready
//
//        printResponse(response);
//
//        break;
//
//    case KUKA_TRAJ_START:
//
//        printResponse(response);
//
//        break;
//
//    case KUKA_TRAJ_DONE:
//
//        printResponse(response);
//
//        break;
//
//    case KUKA_STREAM: //  means "streamed message"
//
//        // capture data from robot to RAM
//        if (nowCapturing)
//        {
//            decision.push_back(currentDecision);
//            tick.push_back(response.info[KUKA_RSP_TICK]);
//            id.push_back(response.info[KUKA_RSP_TRAJID]);
//            pos.push_back(response.frame[KUKA_FRAME_Z]);
//        }
//
//        break;
//    }
}

void HandlingServer::handleDisconnect()
{
    cout << "------------------------------------------------" << endl;
    cout << "HandlingServer: Ending session." << endl;
    cout << "------------------------------------------------" << endl;
}


//void HandlingServer::startCapturing()
//{
//    if (!nowCapturing)
//    {
//        // start capturing frames from robot
//        decision.clear();
//        tick.clear();
//        id.clear();
//        pos.clear();
//
//        nowCapturing = true;
//    }
//    else
//    {
//        cerr << "Already capturing!" << endl;
//    }
//}

void HandlingServer::printResponse(const KukaResponse &response)
{
    cout << "------------------------------------------------" << endl;
    cout << "Response #" << handledCount << endl;

    response.printValues();

    cout << "------------------------------------------------" << endl;

}

//void HandlingServer::finishCapturing()
//{
//    if (!nowCapturing)
//    {
//        cerr << "Not capturing!" << endl;
//        return;
//    }
//
//    // write captured to file
//    cout << "----------------------------------" << endl;
//    std::string captureName = "tick_id_dec_pos.txt";
//    cout << "Filename:  " << captureName << endl;
//    cout << "----------------------------------" << endl;
//    try
//    {
//        std::ofstream captureFile;
//        captureFile.open( captureName );
//
//        for (size_t i = 0; i < decision.size();  ++i)
//        {
//            captureFile << tick[i] << " " << id[i] << " " << decision[i] << " " << pos[i] << "\n";
//        }
//
//    }
//    catch (exception &e)
//    {
//        cerr << "Exception writing captured data to file: " << e.what();
//    }
//
//}
