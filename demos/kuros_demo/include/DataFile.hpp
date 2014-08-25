#ifndef KUROSDATAFILE_H
#define KUROSDATAFILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

#include <kuros_constants.hpp>
#include <types.hpp>

using std::string;
using std::ifstream;

/*
Helper class for loading space-delimited files generated in matlab etc.
Not production-strength but works for simple testing.
*/
class DataFile
{

public:

    DataFile();
    virtual ~DataFile();

    /*
    Load space delimited file with each line containing <framesize> doubles.
    Any line which parses to a different result is ignored.
    */
    void loadSDFrames(const string& filename, trajectory_vec &trajectory, size_t framesize = KUKA_FRAME_SIZE);

    double roundToPrecision(double val);

    void setPrecision(int p);

protected:

private:

    int precision;
    double roundingConstant;


};


#endif // DATAFILE_H
