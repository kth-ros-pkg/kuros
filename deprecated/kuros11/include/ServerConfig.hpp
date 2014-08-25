#ifndef SERVERCONFIG_H
#define SERVERCONFIG_H

#include <XMLParser.hpp>

using boost::lexical_cast;
using boost::bad_lexical_cast;


class ServerConfig : public XMLParser
{
public:

    // ---------------------------------------------------------------------------
    // Constructor / Destructor
    // ---------------------------------------------------------------------------
    ServerConfig();
    virtual ~ServerConfig();

    // ---------------------------------------------------------------------------
    // Public methods
    // ---------------------------------------------------------------------------

    void load();

    void printValues();

    unsigned short getPort();
    size_t getMaxBufferSize();
    std::string getEndString();

protected:

private:

    // ---------------------------------------------------------------------------
    // Private data
    // ---------------------------------------------------------------------------

    std::string filename = "ServerConfig.xml";  // load this

    // default
    unsigned short port = 6008;
    std::string endString = "</Robot>";
    std::size_t maxBufferSize = 2048;

    // ---------------------------------------------------------------------------
    // Private methods
    // ---------------------------------------------------------------------------

    void parse();
};

#endif // SERVERCONFIG_H
