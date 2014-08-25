#include "HandlingServer.hpp"

HandlingServer::HandlingServer() : handledCount(0)
{
    //ctor
}

HandlingServer::~HandlingServer()
{
    //dtor
}

void HandlingServer::handleResponse(const KukaResponse &response)
{

    cout << "------------------------------------------------" << endl;
    cout << "Response #" << handledCount << endl;

    response.printValues();

    cout << "------------------------------------------------" << endl;

    ++handledCount;
}

void HandlingServer::handleDisconnect()
{
    cout << "------------------------------------------------" << endl;
    cout << "HandlingServer: Ending session." << endl;
    cout << "------------------------------------------------" << endl;
}
