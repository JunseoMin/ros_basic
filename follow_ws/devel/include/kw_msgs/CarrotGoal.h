// Generated by gencpp from file kw_msgs/CarrotGoal.msg
// DO NOT EDIT!


#ifndef KW_MSGS_MESSAGE_CARROTGOAL_H
#define KW_MSGS_MESSAGE_CARROTGOAL_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace kw_msgs
{
template <class ContainerAllocator>
struct CarrotGoal_
{
  typedef CarrotGoal_<ContainerAllocator> Type;

  CarrotGoal_()
    : func(0)
    , path(0)  {
    }
  CarrotGoal_(const ContainerAllocator& _alloc)
    : func(0)
    , path(0)  {
  (void)_alloc;
    }



   typedef int8_t _func_type;
  _func_type func;

   typedef int8_t _path_type;
  _path_type path;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(SAVE_WAYPOINT)
  #undef SAVE_WAYPOINT
#endif
#if defined(_WIN32) && defined(FOLLOW_WAYPOINT)
  #undef FOLLOW_WAYPOINT
#endif
#if defined(_WIN32) && defined(PATH_ONE)
  #undef PATH_ONE
#endif
#if defined(_WIN32) && defined(PATH_TWO)
  #undef PATH_TWO
#endif
#if defined(_WIN32) && defined(PATH_THREE)
  #undef PATH_THREE
#endif

  enum {
    SAVE_WAYPOINT = 0,
    FOLLOW_WAYPOINT = 1,
    PATH_ONE = 1,
    PATH_TWO = 2,
    PATH_THREE = 3,
  };


  typedef boost::shared_ptr< ::kw_msgs::CarrotGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::kw_msgs::CarrotGoal_<ContainerAllocator> const> ConstPtr;

}; // struct CarrotGoal_

typedef ::kw_msgs::CarrotGoal_<std::allocator<void> > CarrotGoal;

typedef boost::shared_ptr< ::kw_msgs::CarrotGoal > CarrotGoalPtr;
typedef boost::shared_ptr< ::kw_msgs::CarrotGoal const> CarrotGoalConstPtr;

// constants requiring out of line definition

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::kw_msgs::CarrotGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::kw_msgs::CarrotGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::kw_msgs::CarrotGoal_<ContainerAllocator1> & lhs, const ::kw_msgs::CarrotGoal_<ContainerAllocator2> & rhs)
{
  return lhs.func == rhs.func &&
    lhs.path == rhs.path;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::kw_msgs::CarrotGoal_<ContainerAllocator1> & lhs, const ::kw_msgs::CarrotGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace kw_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::kw_msgs::CarrotGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::kw_msgs::CarrotGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::kw_msgs::CarrotGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "863fc84fc39f4df288540e2439ded070";
  }

  static const char* value(const ::kw_msgs::CarrotGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x863fc84fc39f4df2ULL;
  static const uint64_t static_value2 = 0x88540e2439ded070ULL;
};

template<class ContainerAllocator>
struct DataType< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "kw_msgs/CarrotGoal";
  }

  static const char* value(const ::kw_msgs::CarrotGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# function\n"
"int8 SAVE_WAYPOINT = 0\n"
"int8 FOLLOW_WAYPOINT = 1\n"
"\n"
"# pth num\n"
"int8 PATH_ONE = 1\n"
"int8 PATH_TWO = 2\n"
"int8 PATH_THREE = 3\n"
"\n"
"# action filed\n"
"# Dfine the goal\n"
"int8 func\n"
"int8 path\n"
;
  }

  static const char* value(const ::kw_msgs::CarrotGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.func);
      stream.next(m.path);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CarrotGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::kw_msgs::CarrotGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::kw_msgs::CarrotGoal_<ContainerAllocator>& v)
  {
    s << indent << "func: ";
    Printer<int8_t>::stream(s, indent + "  ", v.func);
    s << indent << "path: ";
    Printer<int8_t>::stream(s, indent + "  ", v.path);
  }
};

} // namespace message_operations
} // namespace ros

#endif // KW_MSGS_MESSAGE_CARROTGOAL_H
