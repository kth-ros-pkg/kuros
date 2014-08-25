#include "ServerConfig.hpp"


ServerConfig::ServerConfig() :
    filename("ServerConfig.xml"),
    port(6008),
    endString("</Robot>"),
    maxBufferSize(1024)
{}

ServerConfig::~ServerConfig() {}

void ServerConfig::load()
{
    try
    {
        errorState = doc.LoadFile(filename.c_str());
    }
    catch (std::exception &e)
    {
        cerr << "ServerConfig load file exception: " << e.what() << endl;
    }

    if (errorState == 0)
    {
        parse();
    }
    else
    {
        cerr << "Could not load ServerConfig.xml, using default settings." << endl;
    }
}

void ServerConfig::printValues()
{

    cout << port << " " << maxBufferSize << " " << endString << endl;
}

void ServerConfig::parse()
{
    XMLHandle docHandle( &doc );
    XMLText *xmltext;
    // port
    xmltext = docHandle.FirstChildElement( "ServerConfig" )
              .FirstChildElement( "Port" )
              .FirstChild()   // this is a text, not an element
              .ToText();

    if( xmltext )
    {
        try
        {
            port = boost::lexical_cast<unsigned short>(xmltext->Value());
        }
        catch (const boost::bad_lexical_cast &e)
        {
            cerr << "Port value exception! Port not changed." << endl;
        }
    }
    else     // node doesnt exist
    {
        nodeNotFound("Port");
    }

    // maxbuffersize
    xmltext = docHandle.FirstChildElement( "ServerConfig" )
              .FirstChildElement( "MaxBufferSize" )
              .FirstChild()   // this is a text, not an element
              .ToText();

    if( xmltext )
    {
        try
        {
            maxBufferSize = boost::lexical_cast<std::size_t>(xmltext->Value());
        }
        catch (const boost::bad_lexical_cast &e)
        {
            cerr << "MaxBufferSize value exception! MaxBufferSize not changed." << endl;
        }
    }
    else     // node doesnt exist
    {
        nodeNotFound("MaxBufferSize");
    }

    // endstring
    xmltext = docHandle.FirstChildElement( "ServerConfig" )
              .FirstChildElement( "EndString" )
              .FirstChild()   // this is a text, not an element
              .ToText();

    if( xmltext )
    {
        try
        {
            endString = std::string(xmltext->Value());
        }
        catch (std::exception &e)
        {
            cerr << "EndString value exception! EndString not changed. " << e.what() << endl;
        }
    }
    else     // node doesnt exist
    {
        nodeNotFound("MaxBufferSize");
    }
}

unsigned short ServerConfig::getPort()
{
    return port;
}
size_t ServerConfig::getMaxBufferSize()
{
    return maxBufferSize;
}
std::string ServerConfig::getEndString()
{
    return endString;    // TODO: endString.c_ptr() ?
}
