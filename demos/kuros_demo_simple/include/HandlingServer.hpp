#ifndef HANDLINGSERVER_HPP
#define HANDLINGSERVER_HPP

#include <kuros.h>

class HandlingServer : public Server
{
    public:
        HandlingServer();
        virtual ~HandlingServer();

        /*
        Handles incoming messages from robot.
        We have access to response object in server.
        */
        void handleResponse(const KukaResponse &response); // override;
        void handleDisconnect(); // override;

    protected:
    private:

        int handledCount;
};

#endif // HANDLINGSERVER_HPP
