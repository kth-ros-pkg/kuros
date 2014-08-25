#ifndef TYPES_HPP_INCLUDED
#define TYPES_HPP_INCLUDED

#include <vector>
#include <iostream>

/*

Some often used types and std's.

*/

typedef std::vector<int> info_vec;
typedef std::vector<double> frame_vec;
typedef std::vector< frame_vec > trajectory_vec;

using std::cout;
using std::cerr;
using std::endl;
//using std::exception;

#endif // TYPES_HPP_INCLUDED
