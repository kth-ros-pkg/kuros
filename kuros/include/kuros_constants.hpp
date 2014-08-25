#ifndef KUROS_CONSTANTS_HPP_INCLUDED
#define KUROS_CONSTANTS_HPP_INCLUDED


const int NO = 0;
const int YES = 1;

/*
Size of info vector to and from robot.
*/
const int KUKA_INFO_SIZE = 7;       // to robot
const int KUKA_RSP_INFO_SIZE = 3;   // response from robot

const int KUKA_FRAME_SIZE = 6;  // frame size
const int KUKA_AXIS_SIZE = 6;  // frame size

/*
Indexes for info vector parameters to robot.
*/
const int KUKA_RMODE  = 0;
const int KUKA_RMS    = 1;
const int KUKA_TRAJID = 2;
const int KUKA_RUN    = 3;
const int KUKA_VEL    = 4;
const int KUKA_TOL    = 5;
const int KUKA_FRAMETYPE  = 6;
//const int KUKA_FRAMECOUNT = 7; not for user

const int KUKA_CARTESIAN = 1;
const int KUKA_AXIS = 2;
const int KUKA_CARTESIAN_REL = 3;
const int KUKA_AXIS_REL = 4;
/*
Indexes for info vector response from robot.
*/
const int KUKA_RSP_STATUS = 0;
const int KUKA_RSP_TRAJID = 1;
const int KUKA_RSP_TICK   = 2;

/*
Response modes.
*/
const int KUKA_RMODE_BASIC = 1; // ready, exiting, traj start, traj end.
const int KUKA_RMODE_STREAM = 3; // BASIC + stream every NN ms

/*
Robot status as sent by the robot
*/
const int KUKA_NOSTATUS = 0;
const int KUKA_READY = 1;
const int KUKA_TRAJ_START = 2;
// status 3 work in progress
const int KUKA_TRAJ_DONE = 4;
const int KUKA_STREAM = 5;

/*
Indexes for frame vector to and from robot.
*/
const int KUKA_FRAME_X    = 0;
const int KUKA_FRAME_Y    = 1;
const int KUKA_FRAME_Z    = 2;
const int KUKA_FRAME_A    = 3;
const int KUKA_FRAME_B    = 4;
const int KUKA_FRAME_C    = 5;

const int KUKA_AXIS_A1    = 0;
const int KUKA_AXIS_A2    = 1;
const int KUKA_AXIS_A3    = 2;
const int KUKA_AXIS_A4    = 3;
const int KUKA_AXIS_A5    = 4;
const int KUKA_AXIS_A6    = 5;

#endif // KUROS_CONSTANTS_HPP_INCLUDED
