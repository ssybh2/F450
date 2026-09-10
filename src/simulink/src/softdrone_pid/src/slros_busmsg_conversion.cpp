#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_builtin_interfaces_Time and builtin_interfaces::msg::Time

void convertFromBus(builtin_interfaces::msg::Time& msgPtr, SL_Bus_builtin_interfaces_Time const* busPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  msgPtr.nanosec =  busPtr->nanosec;
  msgPtr.sec =  busPtr->sec;
}

void convertToBus(SL_Bus_builtin_interfaces_Time* busPtr, const builtin_interfaces::msg::Time& msgPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  busPtr->nanosec =  msgPtr.nanosec;
  busPtr->sec =  msgPtr.sec;
}


// Conversions between SL_Bus_custom_msgs_ReadSBUSRC and custom_msgs::msg::ReadSBUSRC

void convertFromBus(custom_msgs::msg::ReadSBUSRC& msgPtr, SL_Bus_custom_msgs_ReadSBUSRC const* busPtr)
{
  const std::string rosMessageType("custom_msgs/ReadSBUSRC");

  msgPtr.ch17 =  busPtr->ch17;
  msgPtr.ch18 =  busPtr->ch18;
  convertFromBusVariablePrimitiveArray(msgPtr.channels, busPtr->channels, busPtr->channels_SL_Info);
  msgPtr.fail_safe =  busPtr->fail_safe;
  msgPtr.frame_lost =  busPtr->frame_lost;
  convertFromBus(msgPtr.header, &busPtr->header);
  msgPtr.online =  busPtr->online;
}

void convertToBus(SL_Bus_custom_msgs_ReadSBUSRC* busPtr, const custom_msgs::msg::ReadSBUSRC& msgPtr)
{
  const std::string rosMessageType("custom_msgs/ReadSBUSRC");

  busPtr->ch17 =  msgPtr.ch17;
  busPtr->ch18 =  msgPtr.ch18;
  convertToBusVariablePrimitiveArray(busPtr->channels, busPtr->channels_SL_Info, msgPtr.channels, slros::EnabledWarning(rosMessageType, "channels"));
  busPtr->fail_safe =  msgPtr.fail_safe;
  busPtr->frame_lost =  msgPtr.frame_lost;
  convertToBus(&busPtr->header, msgPtr.header);
  busPtr->online =  msgPtr.online;
}


// Conversions between SL_Bus_custom_msgs_WriteOnBoardPWM and custom_msgs::msg::WriteOnBoardPWM

void convertFromBus(custom_msgs::msg::WriteOnBoardPWM& msgPtr, SL_Bus_custom_msgs_WriteOnBoardPWM const* busPtr)
{
  const std::string rosMessageType("custom_msgs/WriteOnBoardPWM");

  msgPtr.channel1 =  busPtr->channel1;
  msgPtr.channel2 =  busPtr->channel2;
  msgPtr.channel3 =  busPtr->channel3;
  msgPtr.channel4 =  busPtr->channel4;
}

void convertToBus(SL_Bus_custom_msgs_WriteOnBoardPWM* busPtr, const custom_msgs::msg::WriteOnBoardPWM& msgPtr)
{
  const std::string rosMessageType("custom_msgs/WriteOnBoardPWM");

  busPtr->channel1 =  msgPtr.channel1;
  busPtr->channel2 =  msgPtr.channel2;
  busPtr->channel3 =  msgPtr.channel3;
  busPtr->channel4 =  msgPtr.channel4;
}


// Conversions between SL_Bus_geometry_msgs_Quaternion and geometry_msgs::msg::Quaternion

void convertFromBus(geometry_msgs::msg::Quaternion& msgPtr, SL_Bus_geometry_msgs_Quaternion const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr.w =  busPtr->w;
  msgPtr.x =  busPtr->x;
  msgPtr.y =  busPtr->y;
  msgPtr.z =  busPtr->z;
}

void convertToBus(SL_Bus_geometry_msgs_Quaternion* busPtr, const geometry_msgs::msg::Quaternion& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  busPtr->w =  msgPtr.w;
  busPtr->x =  msgPtr.x;
  busPtr->y =  msgPtr.y;
  busPtr->z =  msgPtr.z;
}


// Conversions between SL_Bus_geometry_msgs_Vector3 and geometry_msgs::msg::Vector3

void convertFromBus(geometry_msgs::msg::Vector3& msgPtr, SL_Bus_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr.x =  busPtr->x;
  msgPtr.y =  busPtr->y;
  msgPtr.z =  busPtr->z;
}

void convertToBus(SL_Bus_geometry_msgs_Vector3* busPtr, const geometry_msgs::msg::Vector3& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->x =  msgPtr.x;
  busPtr->y =  msgPtr.y;
  busPtr->z =  msgPtr.z;
}


// Conversions between SL_Bus_sensor_msgs_Imu and sensor_msgs::msg::Imu

void convertFromBus(sensor_msgs::msg::Imu& msgPtr, SL_Bus_sensor_msgs_Imu const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/Imu");

  convertFromBus(msgPtr.angular_velocity, &busPtr->angular_velocity);
  convertFromBusFixedPrimitiveArray(msgPtr.angular_velocity_covariance, busPtr->angular_velocity_covariance);
  convertFromBus(msgPtr.header, &busPtr->header);
  convertFromBus(msgPtr.linear_acceleration, &busPtr->linear_acceleration);
  convertFromBusFixedPrimitiveArray(msgPtr.linear_acceleration_covariance, busPtr->linear_acceleration_covariance);
  convertFromBus(msgPtr.orientation, &busPtr->orientation);
  convertFromBusFixedPrimitiveArray(msgPtr.orientation_covariance, busPtr->orientation_covariance);
}

void convertToBus(SL_Bus_sensor_msgs_Imu* busPtr, const sensor_msgs::msg::Imu& msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Imu");

  convertToBus(&busPtr->angular_velocity, msgPtr.angular_velocity);
  convertToBusFixedPrimitiveArray(busPtr->angular_velocity_covariance, msgPtr.angular_velocity_covariance, slros::NoopWarning());
  convertToBus(&busPtr->header, msgPtr.header);
  convertToBus(&busPtr->linear_acceleration, msgPtr.linear_acceleration);
  convertToBusFixedPrimitiveArray(busPtr->linear_acceleration_covariance, msgPtr.linear_acceleration_covariance, slros::NoopWarning());
  convertToBus(&busPtr->orientation, msgPtr.orientation);
  convertToBusFixedPrimitiveArray(busPtr->orientation_covariance, msgPtr.orientation_covariance, slros::NoopWarning());
}


// Conversions between SL_Bus_std_msgs_Header and std_msgs::msg::Header

void convertFromBus(std_msgs::msg::Header& msgPtr, SL_Bus_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr.frame_id, busPtr->frame_id, busPtr->frame_id_SL_Info);
  convertFromBus(msgPtr.stamp, &busPtr->stamp);
}

void convertToBus(SL_Bus_std_msgs_Header* busPtr, const std_msgs::msg::Header& msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->frame_id, busPtr->frame_id_SL_Info, msgPtr.frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  convertToBus(&busPtr->stamp, msgPtr.stamp);
}

