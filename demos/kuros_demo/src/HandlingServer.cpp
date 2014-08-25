#include "HandlingServer.hpp"

HandlingServer::HandlingServer() {}

HandlingServer::~HandlingServer() {}

void HandlingServer::handleResponse(const KukaResponse &response)
{
    ++handledCount;

    // let's capture response stream to file for each trajectory

    //robotStatus = response.info[KUKA_RSP_STATUS];

    switch (response.info[KUKA_RSP_STATUS])
    {
    case KUKA_NOSTATUS: // not connected or exiting
        cout << "Robot offline.\n";
        break;

    case KUKA_READY: // BCO completed, ready
        printResponse(response);

        loadTrajectories(); // load trajectories

        sendNextTrajectory();

        break;

    case KUKA_TRAJ_START: // Received trajectory, about to move
        printResponse(response);

        if (!nowCapturing)
        {
            nowCapturing = true;
            startCapturing(response);
        }

        break;

    case 3: // Received trajectory, about to move
        printResponse(response);

        cout << "We shouldn't be getting status 3, work in progress!" << endl;

        break;

    case KUKA_TRAJ_DONE: // Finished trajectory, ready for next
        printResponse(response);

        if (nowCapturing)
        {
            finishCapturing(response);
        }
        nowCapturing = false;

        // send next available trajectory
        sendNextTrajectory();

        break;

    case KUKA_STREAM: //  means "streamed message"

        // capture frames from robot to RAM
        if (nowCapturing)
        {
            capturedFrames.push_back(response.frame);
        }

        break;
    }
}

void HandlingServer::handleDisconnect()
{
    cout << "Robot disconnected, cleaning up." << endl;

    nowCapturing = false;
    capturedFrames.clear();
    robotStatus = 0;

    while(!trajectoryQueue.empty())
    {
        trajectoryQueue.pop();
    }

    while(!infoQueue.empty())
    {
        infoQueue.pop();
    }
}

void HandlingServer::printResponse(const KukaResponse &response)
{
    cout << "------------------------------------------------" << endl;
    cout << "Response #" << handledCount << endl;

    response.printValues();

    cout << "------------------------------------------------" << endl;

}

void HandlingServer::sendNextTrajectory()
{
    if (!infoQueue.empty() && !trajectoryQueue.empty())
    {
        cout << "Sending next trajectory." << endl;
        sendTrajectory(infoQueue.front(),trajectoryQueue.front());    // send the first one
        infoQueue.pop();
        trajectoryQueue.pop();
    }
}

void HandlingServer::startCapturing(const KukaResponse &response)
{
    // start capturing frames from robot
    capturedFrames.clear();
    capturedFrames.push_back(response.frame);
}

void HandlingServer::finishCapturing(const KukaResponse &response)
{
    // end capturing frames from robot
    capturedFrames.push_back(response.frame);


    // write captured to file
    cout << "----------------------------------" << endl;
    cout << "Saving trajectory id " << response.info[KUKA_RSP_TRAJID] << endl;
    std::string captureName = (boost::format("captured_%1%.txt") %response.info[KUKA_RSP_TRAJID]).str();
    cout << "Filename:  " << captureName << endl;
    cout << "----------------------------------" << endl;
    try
    {
        std::ofstream captureFile;
        captureFile.open( captureName );

        for (auto frame : capturedFrames)
        {
            for (auto val : frame)
            {
                captureFile << val << " ";
            }
            captureFile << "\n";
        }

    }
    catch (exception &e)
    {
        cerr << "Exception writing captured data to file: " << e.what();
    }

}

void HandlingServer::loadTrajectories()
{
    // helper for loading
    DataFile dataFile;

    // load from file
    trajectory_vec trajectory;  // trajectory vector
    dataFile.loadSDFrames(trajectoryFile, trajectory);  // store file contents in trajectory vector

    if (trajectory.empty()) // we don't want to send empty trajectories
    {
        cerr << "Failure loading trajectory!" << endl;
        return;
    }

    // enqueue loaded trajectory (interpolated by robot)
    trajectoryQueue.push(trajectory);
    infoQueue.push(trajInfo);

    // sample some points and make new trajectory (interpolated by robot)
    trajectory_vec pointSampleTrajectory;
    pointSampleTrajectory.push_back(trajectory.front());
    pointSampleTrajectory.push_back(trajectory[10]);
    pointSampleTrajectory.push_back(trajectory[20]);
    pointSampleTrajectory.push_back(trajectory[30]);
    pointSampleTrajectory.push_back(trajectory.back());

    ++trajInfo[KUKA_TRAJID];
    trajectoryQueue.push(pointSampleTrajectory);
    infoQueue.push(trajInfo);

    // sample same points and enqueue as separate trajectories
    // these will be linear (not interpolated by robot)
    trajectory_vec pose;

    pose.push_back(trajectory.front());
    ++trajInfo[KUKA_TRAJID];
    trajectoryQueue.push(pose);
    infoQueue.push(trajInfo);

    pose[0] = trajectory[10];
    ++trajInfo[KUKA_TRAJID];
    trajectoryQueue.push(pose);
    infoQueue.push(trajInfo);

    pose[0] = trajectory[20];
    ++trajInfo[KUKA_TRAJID];
    trajectoryQueue.push(pose);
    infoQueue.push(trajInfo);

    pose[0] = trajectory[30];
    ++trajInfo[KUKA_TRAJID];
    trajectoryQueue.push(pose);
    infoQueue.push(trajInfo);

    pose[0] = trajectory.back();
    ++trajInfo[KUKA_TRAJID];
    trajectoryQueue.push(pose);
    infoQueue.push(trajInfo);

    cout << "Loaded trajectory. TrajectoryQueue has " << trajectoryQueue.size() << " items and infoQueue has " << infoQueue.size() << " items." << endl;

}
