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

    std::string filename;  // load this

    // default
    unsigned short port;
    std::string endString;
    std::size_t maxBufferSize;

    // ---------------------------------------------------------------------------
    // Private methods
    // ---------------------------------------------------------------------------

    void parse();
};

#endif // SERVERCONFIG_H
