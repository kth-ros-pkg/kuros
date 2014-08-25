#ifndef KUKARESPONSE_H
#define KUKARESPONSE_H

#include <vector>

#include <kuros_constants.hpp>
#include <XMLParser.hpp>

#include <boost/foreach.hpp>

using boost::lexical_cast;
using boost::bad_lexical_cast;

class KukaResponse : public XMLParser
{
public:

    // ---------------------------------------------------------------------------
    // Public Data
    // ---------------------------------------------------------------------------
    std::vector<int> info;
    std::vector<double> frame;
    std::vector<double> axis;

    // ---------------------------------------------------------------------------
    // Constructor / Destructor
    // ---------------------------------------------------------------------------

    KukaResponse();

    virtual ~KukaResponse();

    // ---------------------------------------------------------------------------
    // Public Methods
    // ---------------------------------------------------------------------------

    // parses and stores internally
    void parse(boost::asio::streambuf &message);

    /*
        Status Id Tick
    */
    std::vector<int> getInfo();

    /*
        X Y Z A B C
    */
    std::vector<double> getFrame();

    /*
        a1 a2 a3 a4 a5 a6
    */
    std::vector<double> getAxis();

    void printValues() const;

protected:

private:

    // ---------------------------------------------------------------------------
    // Private Data
    // ---------------------------------------------------------------------------



};

#endif // KUKARESPONSE_H


