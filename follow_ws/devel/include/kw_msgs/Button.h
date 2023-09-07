// Generated by gencpp from file kw_msgs/Button.msg
// DO NOT EDIT!


#ifndef KW_MSGS_MESSAGE_BUTTON_H
#define KW_MSGS_MESSAGE_BUTTON_H

#include <ros/service_traits.h>


#include <kw_msgs/ButtonRequest.h>
#include <kw_msgs/ButtonResponse.h>


namespace kw_msgs
{

struct Button
{

typedef ButtonRequest Request;
typedef ButtonResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Button
} // namespace kw_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::kw_msgs::Button > {
  static const char* value()
  {
    return "3da1caf570615076e9b296a945eee01a";
  }

  static const char* value(const ::kw_msgs::Button&) { return value(); }
};

template<>
struct DataType< ::kw_msgs::Button > {
  static const char* value()
  {
    return "kw_msgs/Button";
  }

  static const char* value(const ::kw_msgs::Button&) { return value(); }
};


// service_traits::MD5Sum< ::kw_msgs::ButtonRequest> should match
// service_traits::MD5Sum< ::kw_msgs::Button >
template<>
struct MD5Sum< ::kw_msgs::ButtonRequest>
{
  static const char* value()
  {
    return MD5Sum< ::kw_msgs::Button >::value();
  }
  static const char* value(const ::kw_msgs::ButtonRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::kw_msgs::ButtonRequest> should match
// service_traits::DataType< ::kw_msgs::Button >
template<>
struct DataType< ::kw_msgs::ButtonRequest>
{
  static const char* value()
  {
    return DataType< ::kw_msgs::Button >::value();
  }
  static const char* value(const ::kw_msgs::ButtonRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::kw_msgs::ButtonResponse> should match
// service_traits::MD5Sum< ::kw_msgs::Button >
template<>
struct MD5Sum< ::kw_msgs::ButtonResponse>
{
  static const char* value()
  {
    return MD5Sum< ::kw_msgs::Button >::value();
  }
  static const char* value(const ::kw_msgs::ButtonResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::kw_msgs::ButtonResponse> should match
// service_traits::DataType< ::kw_msgs::Button >
template<>
struct DataType< ::kw_msgs::ButtonResponse>
{
  static const char* value()
  {
    return DataType< ::kw_msgs::Button >::value();
  }
  static const char* value(const ::kw_msgs::ButtonResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // KW_MSGS_MESSAGE_BUTTON_H
