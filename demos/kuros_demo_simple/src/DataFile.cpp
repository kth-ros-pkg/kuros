#include "DataFile.hpp"

DataFile::DataFile() :
    precision(8)

{
    roundingConstant = pow(10, precision);
}

DataFile::~DataFile() {}

void DataFile::loadSDFrames(const string& filename, trajectory_vec &trajectory, size_t framesize)
{

    std::string line;
    std::ifstream file(filename.c_str());

    boost::char_separator<char> spaceSeparator(" ");

    if (file.is_open())
    {

        while ( getline(file,line) )
        {

            boost::tokenizer<boost::char_separator<char> > tokens(line, spaceSeparator);

            frame_vec frame;

            //for (const auto &token : tokens)    // token content should be a double
            //for (boost::tokenizer<>::iterator tok=tokens.begin(); tok!=tokens.end(); ++tok)
            BOOST_FOREACH(const std::string &token, tokens)
            {
                try
                {
                    frame.push_back(boost::lexical_cast<double>(token));
                }
                catch (std::exception& e)
                {
                    cerr << "Cast to double in data file failed for token " << token << ". "<< e.what();
                }
            }

            // only use line if there are correct number of tokens
            if (frame.size() == framesize)   // TODO: rewrite this hack
            {
                trajectory.push_back(frame);    // TODO: is this efficient copywise?
            }
            else
            {
                cerr << "An invalid frame has been ignored. " << endl;
            }
        }

        file.close();
    }
    else
    {
        cerr << "Unable to open space delimited data file " << filename << endl;
    }
}

double DataFile::roundToPrecision(double val)
{
    return floorf(val * roundingConstant + 0.5) / roundingConstant;
}

void DataFile::setPrecision(int p)
{
    precision = p;
    roundingConstant = pow(10, precision);
}
