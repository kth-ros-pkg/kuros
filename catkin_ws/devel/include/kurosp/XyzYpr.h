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
 * Auto-generated by genmsg_cpp from file /home/mh/catkin_ws/src/kurosp/msg/XyzYpr.msg
 *
 */


#ifndef KUROSP_MESSAGE_XYZYPR_H
#define KUROSP_MESSAGE_XYZYPR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace kurosp
{
template <class ContainerAllocator>
struct XyzYpr_
{
  typedef XyzYpr_<ContainerAllocator> Type;

  XyzYpr_()
    : xyzypr()  {
      xyzypr.assign(0.0);
  }
  XyzYpr_(const ContainerAllocator& _alloc)
    : xyzypr()  {
      xyzypr.assign(0.0);
  }



   typedef boost::array<double, 6>  _xyzypr_type;
  _xyzypr_type xyzypr;




  typedef boost::shared_ptr< ::kurosp::XyzYpr_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kurosp::XyzYpr_<ContainerAllocator> const> ConstPtr;

}; // struct XyzYpr_

typedef ::kurosp::XyzYpr_<std::allocator<void> > XyzYpr;

typedef boost::shared_ptr< ::kurosp::XyzYpr > XyzYprPtr;
typedef boost::shared_ptr< ::kurosp::XyzYpr const> XyzYprConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kurosp::XyzYpr_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kurosp::XyzYpr_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace kurosp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'kurosp': ['/home/mh/catkin_ws/src/kurosp/msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::kurosp::XyzYpr_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kurosp::XyzYpr_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kurosp::XyzYpr_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kurosp::XyzYpr_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kurosp::XyzYpr_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kurosp::XyzYpr_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kurosp::XyzYpr_<ContainerAllocator> >
{
  static const char* value()
  {
    return "db1a4820a973384f560b344883116cc9";
  }

  static const char* value(const ::kurosp::XyzYpr_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdb1a4820a973384fULL;
  static const uint64_t static_value2 = 0x560b344883116cc9ULL;
};

template<class ContainerAllocator>
struct DataType< ::kurosp::XyzYpr_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kurosp/XyzYpr";
  }

  static const char* value(const ::kurosp::XyzYpr_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kurosp::XyzYpr_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[6] xyzypr\n\
";
  }

  static const char* value(const ::kurosp::XyzYpr_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kurosp::XyzYpr_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.xyzypr);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct XyzYpr_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kurosp::XyzYpr_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kurosp::XyzYpr_<ContainerAllocator>& v)
  {
    s << indent << "xyzypr[]" << std::endl;
    for (size_t i = 0; i < v.xyzypr.size(); ++i)
    {
      s << indent << "  xyzypr[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.xyzypr[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // KUROSP_MESSAGE_XYZYPR_H
