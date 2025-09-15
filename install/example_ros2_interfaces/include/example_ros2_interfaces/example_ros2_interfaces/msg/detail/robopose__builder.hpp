// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from example_ros2_interfaces:msg/Robopose.idl
// generated code does not contain a copyright notice

#ifndef EXAMPLE_ROS2_INTERFACES__MSG__DETAIL__ROBOPOSE__BUILDER_HPP_
#define EXAMPLE_ROS2_INTERFACES__MSG__DETAIL__ROBOPOSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "example_ros2_interfaces/msg/detail/robopose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace example_ros2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Robopose_pose
{
public:
  explicit Init_Robopose_pose(::example_ros2_interfaces::msg::Robopose & msg)
  : msg_(msg)
  {}
  ::example_ros2_interfaces::msg::Robopose pose(::example_ros2_interfaces::msg::Robopose::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::example_ros2_interfaces::msg::Robopose msg_;
};

class Init_Robopose_status
{
public:
  Init_Robopose_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robopose_pose status(::example_ros2_interfaces::msg::Robopose::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Robopose_pose(msg_);
  }

private:
  ::example_ros2_interfaces::msg::Robopose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::example_ros2_interfaces::msg::Robopose>()
{
  return example_ros2_interfaces::msg::builder::Init_Robopose_status();
}

}  // namespace example_ros2_interfaces

#endif  // EXAMPLE_ROS2_INTERFACES__MSG__DETAIL__ROBOPOSE__BUILDER_HPP_
