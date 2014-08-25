#include "XMLParser.hpp"

XMLParser::XMLParser() {}
XMLParser::~XMLParser() {}

bool XMLParser::isValid()
{
    return valid;
}

const char * XMLParser::streambufToPtr(boost::asio::streambuf &message)
{
    const char* bufPtr=boost::asio::buffer_cast<const char*>(message.data());
    return bufPtr;
}

void XMLParser::malformedXMLError(const char *e)
{
    cout << "XML malformed at: " << e << endl;
    errorState = MALFORMED_XML_ERROR;
    valid = false;
}

void XMLParser::nodeNotFound(const char *e)
{
    cout << "Node not found, value not changed: " << e << endl;
}

void XMLParser::badCast(const char *e)
{
    cout << "Bad cast exception, value not changed: " << e << endl;
    valid = false;
}
