#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <tinyxml2.h>

#include <types.hpp>

using namespace tinyxml2;

/*
Base.
*/
class XMLParser
{
public:

    const int MALFORMED_XML_ERROR = 666;

    XMLParser();
    virtual ~XMLParser();

    bool isValid();

protected:

    int errorState = 0;
    XMLDocument doc;        // tinyxml
    bool valid = true; // this is set to false if there is a malformed XML error

    /*
    Gets pointer to buffer inside streambuf.
    */
    const char * streambufToPtr(boost::asio::streambuf &message);

    void malformedXMLError(const char *e);

    void nodeNotFound(const char *e);

    void badCast(const char *e);

private:

};

#endif // XMLPARSER_H
