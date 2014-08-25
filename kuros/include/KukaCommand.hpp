#ifndef KUKACOMMAND_H
#define KUKACOMMAND_H

#include <types.hpp>
#include <kuros_constants.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>

class KukaCommand
{
public:

    // ---------------------------------------------------------------------------
    // Constructor / Destructor
    // ---------------------------------------------------------------------------

    KukaCommand();

    virtual ~KukaCommand();

    // ---------------------------------------------------------------------------
    // Public methods
    // ---------------------------------------------------------------------------

    /*
        message: a streambuf to fill
        info:   <RMode RMs Id Run Vel FrameType>
        trajectory:  vector of several frames <X Y Z A B C>

        trajectory.size() is used as framecount, make sure frames are valid!
    */
    void formatTrajectory(boost::asio::streambuf &message, const info_vec &info , const trajectory_vec &trajectory);

protected:

private:

};

/*  deprecated
    message: a streambuf to fill
    info:   <RMode RMs Id Run Vel FrameType FrameCount>
    frame:  <X Y Z A B C>
*/
// void formatPose( boost::asio::streambuf &message, const info_vec &info , const frame_vec &frame);

#endif // KUKACOMMAND_H

