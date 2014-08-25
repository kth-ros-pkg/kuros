This is the catkin workspace for building the send_traj_server and the blocksend_traj_server ROS nodes, and their testclients. The testclients roughly correspond to the c++ demos.

Built and tested on ROS indigo and Ubuntu 14.04 LTS.

The workspace is provided as is. Edit the filepaths in the src/CMakeLists.txt file to work with your system.

To run the nodes:

rosrun kurosp send_traj_server
or
rosrun kurosp blocksend_traj_server

then run an appropriate client, for example

rosrun kurosp send_traj_testclient
or
rosrun kurosp blocksend_traj_testclient

IMPORTANT! ROS doesn't support c++11. Make sure you build kuros with the same c++ version as ROS.
