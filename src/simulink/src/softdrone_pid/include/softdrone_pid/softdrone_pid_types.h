//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: softdrone_pid_types.h
//
// Code generated for Simulink model 'softdrone_pid'.
//
// Model version                  : 1.38
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Sep  9 23:44:58 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: AMD->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_softdrone_pid_types_h_
#define RTW_HEADER_softdrone_pid_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_geometry_msgs_Vector3
{
  real_T x;
  real_T y;
  real_T z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_custom_msgs_WriteOnBoardPWM_
#define DEFINED_TYPEDEF_FOR_SL_Bus_custom_msgs_WriteOnBoardPWM_

// MsgType=custom_msgs/WriteOnBoardPWM
struct SL_Bus_custom_msgs_WriteOnBoardPWM
{
  uint16_T channel1;
  uint16_T channel2;
  uint16_T channel3;
  uint16_T channel4;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_

// MsgType=builtin_interfaces/Time
struct SL_Bus_builtin_interfaces_Time
{
  int32_T sec;
  uint32_T nanosec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_std_msgs_Header
{
  // MsgType=builtin_interfaces/Time
  SL_Bus_builtin_interfaces_Time stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=frame_id_SL_Info:TruncateAction=warn 
  uint8_T frame_id[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=frame_id
  SL_Bus_ROSVariableLengthArrayInfo frame_id_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_custom_msgs_ReadSBUSRC_
#define DEFINED_TYPEDEF_FOR_SL_Bus_custom_msgs_ReadSBUSRC_

// MsgType=custom_msgs/ReadSBUSRC
struct SL_Bus_custom_msgs_ReadSBUSRC
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;
  uint8_T online;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=channels_SL_Info:TruncateAction=warn 
  uint16_T channels[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=channels
  SL_Bus_ROSVariableLengthArrayInfo channels_SL_Info;
  uint8_T ch17;
  uint8_T ch18;
  uint8_T fail_safe;
  uint8_T frame_lost;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_geometry_msgs_Quaternion
{
  real_T x;
  real_T y;
  real_T z;
  real_T w;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_Imu_
#define DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_Imu_

// MsgType=sensor_msgs/Imu
struct SL_Bus_sensor_msgs_Imu
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_geometry_msgs_Quaternion orientation;
  real_T orientation_covariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 angular_velocity;
  real_T angular_velocity_covariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 linear_acceleration;
  real_T linear_acceleration_covariance[9];
};

#endif

// Custom Type definition for MATLABSystem: '<S23>/SourceBlock'
#include "rmw/qos_profiles.h"
#ifndef struct_ros_slros2_internal_block_Publisher_softdrone_pid_T
#define struct_ros_slros2_internal_block_Publisher_softdrone_pid_T

struct ros_slros2_internal_block_Publisher_softdrone_pid_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif            // struct_ros_slros2_internal_block_Publisher_softdrone_pid_T

#ifndef struct_ros_slros2_internal_block_Subscriber_softdrone_pid_T
#define struct_ros_slros2_internal_block_Subscriber_softdrone_pid_T

struct ros_slros2_internal_block_Subscriber_softdrone_pid_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif           // struct_ros_slros2_internal_block_Subscriber_softdrone_pid_T

// Parameters (default storage)
typedef struct P_softdrone_pid_T_ P_softdrone_pid_T;

// Forward declaration for rtModel
typedef struct tag_RTM_softdrone_pid_T RT_MODEL_softdrone_pid_T;

#endif                                 // RTW_HEADER_softdrone_pid_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
