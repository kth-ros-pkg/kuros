#ifndef HANDLINGSERVER_HPP
#define HANDLINGSERVER_HPP

#include <kuros.h>

#include <string>
#include <iostream>
#include <fstream>
#include <atomic>


class HandlingServer : public Server
{
public:

    HandlingServer();
    virtual ~HandlingServer();

    void handleResponse(const KukaResponse &response) override;
    void handleDisconnect() override;

    // --------------------------------------------------
    // For capturing data

    //std::atomic<bool> nowCapturing {false}; // set this from main thread

    //std::vector<int> decision;
    //std::vector<int> tick;
    //std::vector<int> id;

    //std::vector<double> pos;

    //std::atomic<int> currentDecision {-1};

    //void saveCaptured();

    //void finishCapturing();

    //void startCapturing();

protected:

private:

    int handledCount = 0;

    void printResponse(const KukaResponse &response);

};

#endif // HANDLINGSERVER_H
