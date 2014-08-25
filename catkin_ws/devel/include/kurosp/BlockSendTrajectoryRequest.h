/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/mh/catkin_ws/src/kurosp/srv/BlockSendTrajectory.srv
 *
 */


#ifndef KUROSP_MESSAGE_BLOCKSENDTRAJECTORYREQUEST_H
#define KUROSP_MESSAGE_BLOCKSENDTRAJECTORYREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <kurosp/XyzYprTrajectory.h>

namespace kurosp
{
template <class ContainerAllocator>
struct BlockSendTrajectoryRequest_
{
  typedef BlockSendTrajectoryRequest_<ContainerAllocator> Type;

  BlockSendTrajectoryRequest_()
    : trajectory()  {
    }
  BlockSendTrajectoryRequest_(const ContainerAllocator& _alloc)
    : trajectory(_alloc)  {
    }



   typedef  ::kurosp::XyzYprTrajectory_<ContainerAllocator>  _trajectory_type;
  _trajectory_type trajectory;




  typedef boost::shared_ptr< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> const> ConstPtr;

}; // struct BlockSendTrajectoryRequest_

typedef ::kurosp::BlockSendTrajectoryRequest_<std::allocator<void> > BlockSendTrajectoryRequest;

typedef boost::shared_ptr< ::kurosp::BlockSendTrajectoryRequest > BlockSendTrajectoryRequestPtr;
typedef boost::shared_ptr< ::kurosp::BlockSendTrajectoryRequest const> BlockSendTrajectoryRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kurosp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'kurosp': ['/home/mh/catkin_ws/src/kurosp/msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ae5f28d08d9a50a9cf93f77fdd3565d1";
  }

  static const char* value(const ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xae5f28d08d9a50a9ULL;
  static const uint64_t static_value2 = 0xcf93f77fdd3565d1ULL;
};

template<class ContainerAllocator>
struct DataType< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kurosp/BlockSendTrajectoryRequest";
  }

  static const char* value(const ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "XyzYprTrajectory trajectory\n\
\n\
================================================================================\n\
MSG: kurosp/XyzYprTrajectory\n\
Info info\n\
XyzYpr[] frames\n\
\n\
================================================================================\n\
MSG: kurosp/Info\n\
uint8 response_mode #= 3 # KUKA_RMODE_STREAM\n\
uint32 response_ms #= 20 # [ms]\n\
uint32 traj_id #= 666 # a trajectory id\n\
bool run #= 1 # YES\n\
uint32 vel #= 200 # [mm/s]\n\
uint32 tol #= 20 # [mm]\n\
uint8 frame_type #= 1 # KUKA_CARTESIAN\n\
\n\
================================================================================\n\
MSG: kurosp/XyzYpr\n\
float64[6] xyzypr\n\
";
  }

  static const char* value(const ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.trajectory);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct BlockSendTrajectoryRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kurosp::BlockSendTrajectoryRequest_<ContainerAllocator>& v)
  {
    s << indent << "trajectory: ";
    s << std::endl;
    Printer< ::kurosp::XyzYprTrajectory_<ContainerAllocator> >::stream(s, indent + "  ", v.trajectory);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KUROSP_MESSAGE_BLOCKSENDTRAJECTORYREQUEST_H
