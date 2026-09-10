//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: softdrone_pid.cpp
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
#include "softdrone_pid.h"
#include "rtwtypes.h"
#include "softdrone_pid_types.h"
#include "softdrone_pid_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rmw/qos_profiles.h"
#include <stddef.h>
#include "rt_defines.h"

// Block signals (default storage)
B_softdrone_pid_T softdrone_pid_B;

// Block states (default storage)
DW_softdrone_pid_T softdrone_pid_DW;

// Real-time model
RT_MODEL_softdrone_pid_T softdrone_pid_M_ = RT_MODEL_softdrone_pid_T();
RT_MODEL_softdrone_pid_T *const softdrone_pid_M = &softdrone_pid_M_;

// Forward declaration for local functions
static real_T softdrone_pid_rt_atan2d_snf(real_T u0, real_T u1);
static void softdrone_pid_SystemCore_setup_fklop
  (ros_slros2_internal_block_Subscriber_softdrone_pid_T *obj);
static void softdrone_pid_SystemCore_setup_fklopg
  (ros_slros2_internal_block_Subscriber_softdrone_pid_T *obj);
static void softdrone_pid_SystemCore_setup_f
  (ros_slros2_internal_block_Subscriber_softdrone_pid_T *obj);
static void softdrone_pid_SystemCore_setup_fk
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj);
static void softdrone_pid_SystemCore_setup
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj);
static void softdrone_pid_SystemCore_setup_fkl
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj);
static void softdrone_pid_SystemCore_setup_fklo
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj);

//
// Output and update for atomic system:
//    '<S24>/Eurle2quat'
//    '<S24>/Eurle2quat1'
//
void softdrone_pid_Eurle2quat(real_T rtu_roll, real_T rtu_pitch, real_T rtu_yaw,
  real_T rty_quaternion[4])
{
  real_T c;
  real_T c_0;
  real_T c_1;
  real_T s_idx_0;
  real_T s_idx_1;
  real_T s_idx_2;
  real_T tmp;
  real_T tmp_0;
  s_idx_0 = rtu_yaw / 2.0;
  s_idx_1 = rtu_pitch / 2.0;
  s_idx_2 = rtu_roll / 2.0;
  c = cos(s_idx_0);
  s_idx_0 = sin(s_idx_0);
  c_0 = cos(s_idx_1);
  s_idx_1 = sin(s_idx_1);
  c_1 = cos(s_idx_2);
  s_idx_2 = sin(s_idx_2);
  tmp = c * c_0;
  tmp_0 = s_idx_0 * s_idx_1;
  rty_quaternion[0] = tmp * c_1 + tmp_0 * s_idx_2;
  rty_quaternion[1] = tmp * s_idx_2 - tmp_0 * c_1;
  tmp = s_idx_0 * c_0;
  tmp_0 = c * s_idx_1;
  rty_quaternion[2] = tmp_0 * c_1 + tmp * s_idx_2;
  rty_quaternion[3] = tmp * c_1 - tmp_0 * s_idx_2;
}

//
// Output and update for atomic system:
//    '<S25>/deadzone2'
//    '<S25>/deadzone3'
//    '<S25>/deadzone4'
//
void softdrone_pid_deadzone2(real_T rtu_u, real_T *rty_y)
{
  real_T u;
  u = rtu_u;
  if (rtu_u < 1100.0) {
    u = 1100.0;
  } else if (rtu_u > 1900.0) {
    u = 1900.0;
  }

  if (u > 1540.0) {
    *rty_y = ((u - 1500.0) - 40.0) * 0.0027777777777777779;
  } else if (u < 1460.0) {
    *rty_y = ((u - 1500.0) + 40.0) * 0.0027777777777777779;
  } else {
    *rty_y = 0.0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// Output and update for atomic system:
//    '<Root>/MATLAB Function10'
//    '<Root>/MATLAB Function2'
//    '<Root>/MATLAB Function3'
//    '<Root>/MATLAB Function4'
//
void softdrone_pid_MATLABFunction10(real_T rtu_u, uint16_T *rty_y)
{
  real_T u;
  u = rtu_u;
  if (rtu_u < 1000.0) {
    u = 1000.0;
  } else if (rtu_u > 2000.0) {
    u = 2000.0;
  }

  u = rt_roundd_snf(u);
  if (u < 65536.0) {
    if (u >= 0.0) {
      *rty_y = static_cast<uint16_T>(u);
    } else {
      *rty_y = 0U;
    }
  } else {
    *rty_y = MAX_uint16_T;
  }
}

//
// Output and update for atomic system:
//    '<Root>/MATLAB Function12'
//    '<Root>/MATLAB Function13'
//    '<Root>/MATLAB Function14'
//    '<Root>/MATLAB Function15'
//
void softdrone_pid_MATLABFunction12(uint16_T rtu_u, real_T *rty_y)
{
  if (rtu_u > 1044) {
    *rty_y = ((static_cast<real_T>(rtu_u) - 1024.0) - 20.0) / 662.0;
  } else if (rtu_u < 1004) {
    *rty_y = ((static_cast<real_T>(rtu_u) - 1024.0) + 20.0) / 663.0;
  } else {
    *rty_y = 0.0;
  }

  if (*rty_y > 1.0) {
    *rty_y = 1.0;
  } else if (*rty_y < -1.0) {
    *rty_y = -1.0;
  }
}

//
// Output and update for atomic system:
//    '<Root>/MATLAB Function7'
//    '<Root>/MATLAB Function8'
//    '<Root>/MATLAB Function9'
//
void softdrone_pid_MATLABFunction7(real_T rtu_u, real_T *rty_y)
{
  *rty_y = rtu_u * 500.0 + 1500.0;
}

static real_T softdrone_pid_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      softdrone_pid_B.i2 = 1;
    } else {
      softdrone_pid_B.i2 = -1;
    }

    if (u1 > 0.0) {
      softdrone_pid_B.i3 = 1;
    } else {
      softdrone_pid_B.i3 = -1;
    }

    y = atan2(static_cast<real_T>(softdrone_pid_B.i2), static_cast<real_T>
              (softdrone_pid_B.i3));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void softdrone_pid_SystemCore_setup_fklop
  (ros_slros2_internal_block_Subscriber_softdrone_pid_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[26];
  static const char_T b_zeroDelimTopic_0[26] = "/ecat/sn1966143/app1/read";

  // Start for MATLABSystem: '<S22>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S22>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 26; i++) {
    // Start for MATLABSystem: '<S22>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_softdrone_pid_430.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

static void softdrone_pid_SystemCore_setup_fklopg
  (ros_slros2_internal_block_Subscriber_softdrone_pid_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[26];
  static const char_T b_zeroDelimTopic_0[26] = "/ecat/sn1966143/app2/read";

  // Start for MATLABSystem: '<S23>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S23>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 26; i++) {
    // Start for MATLABSystem: '<S23>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_softdrone_pid_434.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

static void softdrone_pid_SystemCore_setup_f
  (ros_slros2_internal_block_Subscriber_softdrone_pid_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[31];
  static const char_T b_zeroDelimTopic_0[31] = "/filtered_angular_acceleration";

  // Start for MATLABSystem: '<S37>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S37>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 31; i++) {
    // Start for MATLABSystem: '<S37>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_softdrone_pid_627.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

static void softdrone_pid_SystemCore_setup_fk
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[27];
  static const char_T b_zeroDelimTopic_0[27] = "/ecat/sn1966143/app3/write";

  // Start for MATLABSystem: '<S19>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S19>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 27; i++) {
    // Start for MATLABSystem: '<S19>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_softdrone_pid_451.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

static void softdrone_pid_SystemCore_setup
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[14];
  static const char_T b_zeroDelimTopic_0[14] = "/gyro_rotated";

  // Start for MATLABSystem: '<S36>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S36>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 14; i++) {
    // Start for MATLABSystem: '<S36>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_softdrone_pid_658.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

static void softdrone_pid_SystemCore_setup_fkl
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/imu_angle";

  // Start for MATLABSystem: '<S20>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S20>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S20>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_softdrone_pid_597.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

static void softdrone_pid_SystemCore_setup_fklo
  (ros_slros2_internal_block_Publisher_softdrone_pid_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[10];
  static const char_T b_zeroDelimTopic_0[10] = "/imu_gyro";

  // Start for MATLABSystem: '<S21>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S21>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_ALL, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 10; i++) {
    // Start for MATLABSystem: '<S21>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_softdrone_pid_609.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void softdrone_pid_step(void)
{
  static const int8_T a[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T a_0[9] = { -1, 0, 0, 0, 1, 0, 0, 0, 1 };

  // MATLABSystem: '<S22>/SourceBlock'
  softdrone_pid_B.b_varargout_1 = Sub_softdrone_pid_430.getLatestMessage
    (&softdrone_pid_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S47>/Enable'

  // Start for MATLABSystem: '<S22>/SourceBlock'
  if (softdrone_pid_B.b_varargout_1) {
    // SignalConversion generated from: '<S47>/In1'
    softdrone_pid_B.In1_p = softdrone_pid_B.b_varargout_2_m;
  }

  // End of Start for MATLABSystem: '<S22>/SourceBlock'
  // End of Outputs for SubSystem: '<S22>/Enabled Subsystem'

  // MATLAB Function: '<Root>/MATLAB Function15'
  softdrone_pid_MATLABFunction12(softdrone_pid_B.In1_p.channels[2],
    &softdrone_pid_B.DiscreteTimeIntegrator_f);

  // MATLAB Function: '<Root>/MATLAB Function8'
  softdrone_pid_MATLABFunction7(softdrone_pid_B.DiscreteTimeIntegrator_f,
    &softdrone_pid_B.Conversion3);

  // DataTypeConversion: '<Root>/Data Type Conversion2'
  softdrone_pid_B.u0 = floor(softdrone_pid_B.Conversion3);
  if (rtIsNaN(softdrone_pid_B.u0) || rtIsInf(softdrone_pid_B.u0)) {
    softdrone_pid_B.u0 = 0.0;
  } else {
    softdrone_pid_B.u0 = fmod(softdrone_pid_B.u0, 65536.0);
  }

  if (softdrone_pid_B.u0 < 0.0) {
    softdrone_pid_B.i1 = static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-softdrone_pid_B.u0)));
  } else {
    softdrone_pid_B.i1 = static_cast<uint16_T>(softdrone_pid_B.u0);
  }

  // MATLAB Function: '<S25>/deadzone3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion2'
  //   DataTypeConversion: '<S2>/Conversion9'

  softdrone_pid_deadzone2(static_cast<real_T>(softdrone_pid_B.i1),
    &softdrone_pid_B.Conversion3);

  // Gain: '<S25>/Gain' incorporates:
  //   Constant: '<S25>/Constant'
  //   Sum: '<S25>/Sum'

  softdrone_pid_B.DiscreteTimeIntegrator_f = (softdrone_pid_B.Conversion3 +
    softdrone_pid_P.Constant_Value_d) * softdrone_pid_P.Gain_Gain;

  // MATLAB Function: '<S25>/f1' incorporates:
  //   Constant: '<S25>/thr_hover '

  if (softdrone_pid_B.DiscreteTimeIntegrator_f < 0.5) {
    softdrone_pid_B.DiscreteTimeIntegrator_f = 2.0 *
      softdrone_pid_B.DiscreteTimeIntegrator_f * softdrone_pid_P.THR_HOVER;
  } else {
    softdrone_pid_B.DiscreteTimeIntegrator_f =
      (softdrone_pid_B.DiscreteTimeIntegrator_f - 0.5) * 2.0 * (1.0 -
      softdrone_pid_P.THR_HOVER) + softdrone_pid_P.THR_HOVER;
  }

  // Saturate: '<S25>/Saturation10' incorporates:
  //   MATLAB Function: '<S25>/f1'

  if (softdrone_pid_B.DiscreteTimeIntegrator_f >
      softdrone_pid_P.Saturation10_UpperSat) {
    softdrone_pid_B.DiscreteTimeIntegrator_f =
      softdrone_pid_P.Saturation10_UpperSat;
  } else if (softdrone_pid_B.DiscreteTimeIntegrator_f <
             softdrone_pid_P.Saturation10_LowerSat) {
    softdrone_pid_B.DiscreteTimeIntegrator_f =
      softdrone_pid_P.Saturation10_LowerSat;
  }

  // End of Saturate: '<S25>/Saturation10'

  // MATLABSystem: '<S23>/SourceBlock'
  softdrone_pid_B.b_varargout_1 = Sub_softdrone_pid_434.getLatestMessage
    (&softdrone_pid_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S48>/Enable'

  // Start for MATLABSystem: '<S23>/SourceBlock'
  if (softdrone_pid_B.b_varargout_1) {
    // SignalConversion generated from: '<S48>/In1'
    softdrone_pid_B.In1 = softdrone_pid_B.b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S23>/SourceBlock'
  // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'

  // MATLAB Function: '<Root>/MATLAB Function1'
  for (softdrone_pid_B.i1 = 0; softdrone_pid_B.i1 < 3; softdrone_pid_B.i1++) {
    softdrone_pid_B.gyro_data_rotated[softdrone_pid_B.i1] = (static_cast<real_T>
      (a[softdrone_pid_B.i1 + 3]) * softdrone_pid_B.In1.angular_velocity.y +
      static_cast<real_T>(a[softdrone_pid_B.i1]) *
      softdrone_pid_B.In1.angular_velocity.x) + static_cast<real_T>
      (a[softdrone_pid_B.i1 + 6]) * softdrone_pid_B.In1.angular_velocity.z;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // MATLAB Function: '<Root>/MATLAB Function13'
  softdrone_pid_MATLABFunction12(softdrone_pid_B.In1_p.channels[0],
    &softdrone_pid_B.Conversion3);

  // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
  //   Gain: '<Root>/Gain8'
  //   MATLAB Function: '<Root>/MATLAB Function6'

  softdrone_pid_B.u0 = floor(softdrone_pid_P.Gain8_Gain *
    softdrone_pid_B.Conversion3 * 500.0 + 1500.0);
  if (rtIsNaN(softdrone_pid_B.u0) || rtIsInf(softdrone_pid_B.u0)) {
    softdrone_pid_B.u0 = 0.0;
  } else {
    softdrone_pid_B.u0 = fmod(softdrone_pid_B.u0, 65536.0);
  }

  if (softdrone_pid_B.u0 < 0.0) {
    softdrone_pid_B.Dshot2 = static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-softdrone_pid_B.u0)));
  } else {
    softdrone_pid_B.Dshot2 = static_cast<uint16_T>(softdrone_pid_B.u0);
  }

  // End of DataTypeConversion: '<Root>/Data Type Conversion'

  // MATLAB Function: '<S25>/deadzone1' incorporates:
  //   DataTypeConversion: '<S2>/Conversion7'

  softdrone_pid_B.u = softdrone_pid_B.Dshot2;
  if (softdrone_pid_B.Dshot2 < 1100) {
    softdrone_pid_B.u = 1100;
  } else if (softdrone_pid_B.Dshot2 > 1900) {
    softdrone_pid_B.u = 1900;
  }

  // MATLAB Function: '<Root>/MATLAB Function14'
  softdrone_pid_MATLABFunction12(softdrone_pid_B.In1_p.channels[1],
    &softdrone_pid_B.Conversion3);

  // MATLAB Function: '<Root>/MATLAB Function7' incorporates:
  //   Gain: '<Root>/Gain6'

  softdrone_pid_MATLABFunction7(softdrone_pid_P.Gain6_Gain *
    softdrone_pid_B.Conversion3, &softdrone_pid_B.Conversion3);

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  softdrone_pid_B.u0 = floor(softdrone_pid_B.Conversion3);
  if (rtIsNaN(softdrone_pid_B.u0) || rtIsInf(softdrone_pid_B.u0)) {
    softdrone_pid_B.u0 = 0.0;
  } else {
    softdrone_pid_B.u0 = fmod(softdrone_pid_B.u0, 65536.0);
  }

  if (softdrone_pid_B.u0 < 0.0) {
    softdrone_pid_B.i1 = static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-softdrone_pid_B.u0)));
  } else {
    softdrone_pid_B.i1 = static_cast<uint16_T>(softdrone_pid_B.u0);
  }

  // MATLAB Function: '<S25>/deadzone2' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'
  //   DataTypeConversion: '<S2>/Conversion8'

  softdrone_pid_deadzone2(static_cast<real_T>(softdrone_pid_B.i1),
    &softdrone_pid_B.Conversion3);

  // MATLAB Function: '<Root>/MATLAB Function5'
  for (softdrone_pid_B.i1 = 0; softdrone_pid_B.i1 < 9; softdrone_pid_B.i1++) {
    softdrone_pid_B.R_tmp_c[softdrone_pid_B.i1] = a_0[softdrone_pid_B.i1];
  }

  softdrone_pid_B.u0 = softdrone_pid_B.In1.orientation.z *
    softdrone_pid_B.In1.orientation.z;
  softdrone_pid_B.Saturation1_m = softdrone_pid_B.In1.orientation.y *
    softdrone_pid_B.In1.orientation.y;
  softdrone_pid_B.dv[0] = 1.0 - (softdrone_pid_B.Saturation1_m +
    softdrone_pid_B.u0) * 2.0;
  softdrone_pid_B.u0_tmp = softdrone_pid_B.In1.orientation.x *
    softdrone_pid_B.In1.orientation.y;
  softdrone_pid_B.tr = softdrone_pid_B.In1.orientation.w *
    softdrone_pid_B.In1.orientation.z;
  softdrone_pid_B.dv[3] = (softdrone_pid_B.u0_tmp - softdrone_pid_B.tr) * 2.0;
  softdrone_pid_B.qx = softdrone_pid_B.In1.orientation.x *
    softdrone_pid_B.In1.orientation.z;
  softdrone_pid_B.qy = softdrone_pid_B.In1.orientation.w *
    softdrone_pid_B.In1.orientation.y;
  softdrone_pid_B.dv[6] = (softdrone_pid_B.qx + softdrone_pid_B.qy) * 2.0;
  softdrone_pid_B.dv[1] = (softdrone_pid_B.u0_tmp + softdrone_pid_B.tr) * 2.0;
  softdrone_pid_B.u0_tmp = softdrone_pid_B.In1.orientation.x *
    softdrone_pid_B.In1.orientation.x;
  softdrone_pid_B.dv[4] = 1.0 - (softdrone_pid_B.u0_tmp + softdrone_pid_B.u0) *
    2.0;
  softdrone_pid_B.u0 = softdrone_pid_B.In1.orientation.y *
    softdrone_pid_B.In1.orientation.z;
  softdrone_pid_B.tr = softdrone_pid_B.In1.orientation.w *
    softdrone_pid_B.In1.orientation.x;
  softdrone_pid_B.dv[7] = (softdrone_pid_B.u0 - softdrone_pid_B.tr) * 2.0;
  softdrone_pid_B.dv[2] = (softdrone_pid_B.qx - softdrone_pid_B.qy) * 2.0;
  softdrone_pid_B.dv[5] = (softdrone_pid_B.u0 + softdrone_pid_B.tr) * 2.0;
  softdrone_pid_B.dv[8] = 1.0 - (softdrone_pid_B.u0_tmp +
    softdrone_pid_B.Saturation1_m) * 2.0;
  for (softdrone_pid_B.i1 = 0; softdrone_pid_B.i1 < 3; softdrone_pid_B.i1++) {
    softdrone_pid_B.R_tmp_k = softdrone_pid_B.R_tmp_c[softdrone_pid_B.i1 + 3];
    softdrone_pid_B.R_tmp_cx = softdrone_pid_B.R_tmp_c[softdrone_pid_B.i1];
    softdrone_pid_B.R_tmp_b = softdrone_pid_B.R_tmp_c[softdrone_pid_B.i1 + 6];
    for (softdrone_pid_B.i = 0; softdrone_pid_B.i < 3; softdrone_pid_B.i++) {
      softdrone_pid_B.R_tmp[softdrone_pid_B.i1 + 3 * softdrone_pid_B.i] =
        (softdrone_pid_B.dv[3 * softdrone_pid_B.i + 1] * static_cast<real_T>
         (softdrone_pid_B.R_tmp_k) + softdrone_pid_B.dv[3 * softdrone_pid_B.i] *
         static_cast<real_T>(softdrone_pid_B.R_tmp_cx)) + softdrone_pid_B.dv[3 *
        softdrone_pid_B.i + 2] * static_cast<real_T>(softdrone_pid_B.R_tmp_b);
    }

    softdrone_pid_B.tr = softdrone_pid_B.R_tmp[softdrone_pid_B.i1 + 3];
    softdrone_pid_B.qx = softdrone_pid_B.R_tmp[softdrone_pid_B.i1];
    softdrone_pid_B.qy = softdrone_pid_B.R_tmp[softdrone_pid_B.i1 + 6];
    for (softdrone_pid_B.i = 0; softdrone_pid_B.i < 3; softdrone_pid_B.i++) {
      softdrone_pid_B.R[softdrone_pid_B.i1 + 3 * softdrone_pid_B.i] = (
        static_cast<real_T>(softdrone_pid_B.R_tmp_c[3 * softdrone_pid_B.i + 1]) *
        softdrone_pid_B.tr + static_cast<real_T>(softdrone_pid_B.R_tmp_c[3 *
        softdrone_pid_B.i]) * softdrone_pid_B.qx) + static_cast<real_T>
        (softdrone_pid_B.R_tmp_c[3 * softdrone_pid_B.i + 2]) *
        softdrone_pid_B.qy;
    }
  }

  softdrone_pid_B.tr = (softdrone_pid_B.R[0] + softdrone_pid_B.R[4]) +
    softdrone_pid_B.R[8];
  if (softdrone_pid_B.tr > 0.0) {
    softdrone_pid_B.S = sqrt(softdrone_pid_B.tr + 1.0) * 2.0;
    softdrone_pid_B.tr = 0.25 * softdrone_pid_B.S;
    softdrone_pid_B.qx = (softdrone_pid_B.R[5] - softdrone_pid_B.R[7]) /
      softdrone_pid_B.S;
    softdrone_pid_B.qy = (softdrone_pid_B.R[6] - softdrone_pid_B.R[2]) /
      softdrone_pid_B.S;
    softdrone_pid_B.S = (softdrone_pid_B.R[1] - softdrone_pid_B.R[3]) /
      softdrone_pid_B.S;
  } else if ((softdrone_pid_B.R[0] > softdrone_pid_B.R[4]) &&
             (softdrone_pid_B.R[0] > softdrone_pid_B.R[8])) {
    softdrone_pid_B.S = sqrt(((softdrone_pid_B.R[0] + 1.0) - softdrone_pid_B.R[4])
      - softdrone_pid_B.R[8]) * 2.0;
    softdrone_pid_B.tr = (softdrone_pid_B.R[5] - softdrone_pid_B.R[7]) /
      softdrone_pid_B.S;
    softdrone_pid_B.qx = 0.25 * softdrone_pid_B.S;
    softdrone_pid_B.qy = (softdrone_pid_B.R[1] + softdrone_pid_B.R[3]) /
      softdrone_pid_B.S;
    softdrone_pid_B.S = (softdrone_pid_B.R[2] + softdrone_pid_B.R[6]) /
      softdrone_pid_B.S;
  } else if (softdrone_pid_B.R[4] > softdrone_pid_B.R[8]) {
    softdrone_pid_B.S = sqrt(((softdrone_pid_B.R[4] + 1.0) - softdrone_pid_B.R[0])
      - softdrone_pid_B.R[8]) * 2.0;
    softdrone_pid_B.tr = (softdrone_pid_B.R[6] - softdrone_pid_B.R[2]) /
      softdrone_pid_B.S;
    softdrone_pid_B.qx = (softdrone_pid_B.R[1] + softdrone_pid_B.R[3]) /
      softdrone_pid_B.S;
    softdrone_pid_B.qy = 0.25 * softdrone_pid_B.S;
    softdrone_pid_B.S = (softdrone_pid_B.R[5] + softdrone_pid_B.R[7]) /
      softdrone_pid_B.S;
  } else {
    softdrone_pid_B.S = sqrt(((softdrone_pid_B.R[8] + 1.0) - softdrone_pid_B.R[0])
      - softdrone_pid_B.R[4]) * 2.0;
    softdrone_pid_B.tr = (softdrone_pid_B.R[1] - softdrone_pid_B.R[3]) /
      softdrone_pid_B.S;
    softdrone_pid_B.qx = (softdrone_pid_B.R[2] + softdrone_pid_B.R[6]) /
      softdrone_pid_B.S;
    softdrone_pid_B.qy = (softdrone_pid_B.R[5] + softdrone_pid_B.R[7]) /
      softdrone_pid_B.S;
    softdrone_pid_B.S *= 0.25;
  }

  softdrone_pid_B.q2[0] = softdrone_pid_B.tr;
  softdrone_pid_B.q2[1] = softdrone_pid_B.qx;
  softdrone_pid_B.q2[2] = softdrone_pid_B.qy;
  softdrone_pid_B.q2[3] = softdrone_pid_B.S;
  if (softdrone_pid_B.tr < 0.0) {
    softdrone_pid_B.q2[0] = -softdrone_pid_B.tr;
    softdrone_pid_B.q2[1] = -softdrone_pid_B.qx;
    softdrone_pid_B.q2[2] = -softdrone_pid_B.qy;
    softdrone_pid_B.q2[3] = -softdrone_pid_B.S;
  }

  // MATLAB Function: '<Root>/MATLAB Function11' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function5'

  softdrone_pid_B.qy = softdrone_pid_B.q2[2] * softdrone_pid_B.q2[2];
  softdrone_pid_B.tr = softdrone_pid_rt_atan2d_snf((softdrone_pid_B.q2[0] *
    softdrone_pid_B.q2[3] + softdrone_pid_B.q2[1] * softdrone_pid_B.q2[2]) * 2.0,
    1.0 - (softdrone_pid_B.q2[3] * softdrone_pid_B.q2[3] + softdrone_pid_B.qy) *
    2.0);
  softdrone_pid_B.qx = asin((softdrone_pid_B.q2[0] * softdrone_pid_B.q2[2] -
    softdrone_pid_B.q2[1] * softdrone_pid_B.q2[3]) * 2.0);
  softdrone_pid_B.qy = softdrone_pid_rt_atan2d_snf((softdrone_pid_B.q2[0] *
    softdrone_pid_B.q2[1] + softdrone_pid_B.q2[2] * softdrone_pid_B.q2[3]) * 2.0,
    1.0 - (softdrone_pid_B.q2[1] * softdrone_pid_B.q2[1] + softdrone_pid_B.qy) *
    2.0);

  // MATLAB Function: '<S25>/deadzone1'
  if (softdrone_pid_B.u > 1540) {
    softdrone_pid_B.u0 = ((static_cast<real_T>(softdrone_pid_B.u) - 1500.0) -
                          40.0) * 0.0027777777777777779;
  } else if (softdrone_pid_B.u < 1460) {
    softdrone_pid_B.u0 = ((static_cast<real_T>(softdrone_pid_B.u) - 1500.0) +
                          40.0) * 0.0027777777777777779;
  } else {
    softdrone_pid_B.u0 = 0.0;
  }

  // Saturate: '<S25>/Saturation9' incorporates:
  //   MATLAB Function: '<S25>/deadzone1'

  if (softdrone_pid_B.u0 > softdrone_pid_P.Saturation9_UpperSat) {
    softdrone_pid_B.u0 = softdrone_pid_P.Saturation9_UpperSat;
  } else if (softdrone_pid_B.u0 < softdrone_pid_P.Saturation9_LowerSat) {
    softdrone_pid_B.u0 = softdrone_pid_P.Saturation9_LowerSat;
  }

  // Saturate: '<S25>/Saturation8'
  if (softdrone_pid_B.Conversion3 > softdrone_pid_P.Saturation8_UpperSat) {
    softdrone_pid_B.Conversion3 = softdrone_pid_P.Saturation8_UpperSat;
  } else if (softdrone_pid_B.Conversion3 < softdrone_pid_P.Saturation8_LowerSat)
  {
    softdrone_pid_B.Conversion3 = softdrone_pid_P.Saturation8_LowerSat;
  }

  // MATLAB Function: '<S24>/Eurle2quat1' incorporates:
  //   Gain: '<S25>/Gain1'
  //   Gain: '<S25>/Gain3'
  //   Gain: '<S25>/deg2rad1'
  //   Gain: '<S25>/deg2rad2'
  //   MATLAB Function: '<Root>/MATLAB Function'
  //   Saturate: '<S25>/Saturation8'
  //   Saturate: '<S25>/Saturation9'

  softdrone_pid_Eurle2quat(softdrone_pid_P.DEG2RAD *
    (softdrone_pid_P.MAX_CONTROL_ANGLE_ROLL * softdrone_pid_B.u0),
    softdrone_pid_P.DEG2RAD * (softdrone_pid_P.MAX_CONTROL_ANGLE_PITCH *
    softdrone_pid_B.Conversion3), softdrone_pid_B.tr, softdrone_pid_B.q2);

  // MATLAB Function: '<S24>/Eurle2quat' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function'

  softdrone_pid_Eurle2quat(softdrone_pid_B.qy, softdrone_pid_B.qx,
    softdrone_pid_B.tr, softdrone_pid_B.quaternion_k);

  // Switch: '<S29>/Switch' incorporates:
  //   Constant: '<S29>/Constant'
  //   Constant: '<S29>/Constant1'
  //   MATLAB Function: '<S29>/MATLAB Function'

  if (((softdrone_pid_B.quaternion_k[0] * softdrone_pid_B.q2[0] -
        -softdrone_pid_B.quaternion_k[1] * softdrone_pid_B.q2[1]) -
       -softdrone_pid_B.quaternion_k[2] * softdrone_pid_B.q2[2]) -
      -softdrone_pid_B.quaternion_k[3] * softdrone_pid_B.q2[3] >=
      softdrone_pid_P.Switch_Threshold) {
    softdrone_pid_B.DiscreteTimeIntegrator_g = softdrone_pid_P.Constant1_Value;
  } else {
    softdrone_pid_B.DiscreteTimeIntegrator_g = softdrone_pid_P.Constant_Value_pp;
  }

  // End of Switch: '<S29>/Switch'

  // Gain: '<S29>/Gain1'
  softdrone_pid_B.u0 = 2.0 / softdrone_pid_P.TIME_Constant;

  // Gain: '<S29>/Gain' incorporates:
  //   Gain: '<S29>/Gain1'
  //   MATLAB Function: '<S29>/MATLAB Function'
  //   Product: '<S29>/Product'

  softdrone_pid_B.Saturation1_m = 2.0 * softdrone_pid_P.Kp_ANGLE;
  softdrone_pid_B.S = (((softdrone_pid_B.quaternion_k[0] * softdrone_pid_B.q2[1]
    + softdrone_pid_B.q2[0] * -softdrone_pid_B.quaternion_k[1]) +
                        -softdrone_pid_B.quaternion_k[2] * softdrone_pid_B.q2[3])
                       - softdrone_pid_B.q2[2] * -softdrone_pid_B.quaternion_k[3])
    * softdrone_pid_B.u0 * softdrone_pid_B.DiscreteTimeIntegrator_g *
    softdrone_pid_B.Saturation1_m;
  softdrone_pid_B.Conversion3 = (((softdrone_pid_B.quaternion_k[0] *
    softdrone_pid_B.q2[2] - -softdrone_pid_B.quaternion_k[1] *
    softdrone_pid_B.q2[3]) + softdrone_pid_B.q2[0] *
    -softdrone_pid_B.quaternion_k[2]) + softdrone_pid_B.q2[1] *
    -softdrone_pid_B.quaternion_k[3]) * softdrone_pid_B.u0 *
    softdrone_pid_B.DiscreteTimeIntegrator_g * softdrone_pid_B.Saturation1_m;

  // Saturate: '<S24>/ROLL'
  if (softdrone_pid_B.S > softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_ROLL) {
    softdrone_pid_B.S = softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_ROLL;
  } else if (softdrone_pid_B.S < -softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_ROLL) {
    softdrone_pid_B.S = -softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_ROLL;
  }

  // Gain: '<S34>/Gain' incorporates:
  //   Saturate: '<S24>/ROLL'
  //   Sum: '<S34>/Sum'

  softdrone_pid_B.S = (softdrone_pid_B.S - softdrone_pid_B.gyro_data_rotated[0])
    * softdrone_pid_P.K_ROLL_AngleRate;

  // DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
  //   Constant: '<S1>/Constant'
  //   RelationalOperator: '<S1>/Compare'

  softdrone_pid_B.Dshot2 = (softdrone_pid_B.In1_p.channels[4] >=
    softdrone_pid_P.CompareToConstant_const);

  // Logic: '<S2>/Logical Operator1' incorporates:
  //   Constant: '<S46>/Constant'
  //   Logic: '<S2>/Logical Operator'
  //   RelationalOperator: '<S46>/Compare'

  softdrone_pid_B.LogicalOperator1 = ((softdrone_pid_B.DiscreteTimeIntegrator_f <=
    softdrone_pid_P.CompareToConstant3_const) || (softdrone_pid_B.Dshot2 == 0));

  // DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  if (softdrone_pid_B.LogicalOperator1 ||
      (softdrone_pid_DW.DiscreteTimeIntegrator_PrevResetState != 0)) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE =
      softdrone_pid_P.DiscreteTimeIntegrator_IC;
  }

  // MATLABSystem: '<S37>/SourceBlock'
  softdrone_pid_B.b_varargout_1 = Sub_softdrone_pid_627.getLatestMessage
    (&softdrone_pid_B.BusCreator);

  // Outputs for Enabled SubSystem: '<S37>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S40>/Enable'

  // Start for MATLABSystem: '<S37>/SourceBlock'
  if (softdrone_pid_B.b_varargout_1) {
    // SignalConversion generated from: '<S40>/In1'
    softdrone_pid_B.In1_a = softdrone_pid_B.BusCreator;
  }

  // End of Start for MATLABSystem: '<S37>/SourceBlock'
  // End of Outputs for SubSystem: '<S37>/Enabled Subsystem'

  // MATLAB Function: '<S24>/MATLAB Function1'
  for (softdrone_pid_B.i1 = 0; softdrone_pid_B.i1 < 3; softdrone_pid_B.i1++) {
    softdrone_pid_B.gyro_data_rotated_g[softdrone_pid_B.i1] =
      (static_cast<real_T>(a[softdrone_pid_B.i1 + 3]) * softdrone_pid_B.In1_a.y
       + static_cast<real_T>(a[softdrone_pid_B.i1]) * softdrone_pid_B.In1_a.x) +
      static_cast<real_T>(a[softdrone_pid_B.i1 + 6]) * softdrone_pid_B.In1_a.z;
  }

  // End of MATLAB Function: '<S24>/MATLAB Function1'

  // Sum: '<S34>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  //   Gain: '<S34>/Gain1'
  //   Gain: '<S34>/Gain2'
  //   Gain: '<S34>/Gain3'
  //   Gain: '<S34>/Gain4'

  softdrone_pid_B.Saturation = (softdrone_pid_P.Kp_ROLL_AngleRate *
    softdrone_pid_B.S + softdrone_pid_P.Ki_ROLL_AngleRate *
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE) -
    softdrone_pid_P.K_ROLL_AngleRate * softdrone_pid_B.gyro_data_rotated_g[0] *
    softdrone_pid_P.Kd_ROLL_AngleRate;

  // Saturate: '<S34>/Saturation'
  if (softdrone_pid_B.Saturation > softdrone_pid_P.Saturation_UpperSat) {
    softdrone_pid_B.Saturation = softdrone_pid_P.Saturation_UpperSat;
  } else if (softdrone_pid_B.Saturation < softdrone_pid_P.Saturation_LowerSat) {
    softdrone_pid_B.Saturation = softdrone_pid_P.Saturation_LowerSat;
  }

  // End of Saturate: '<S34>/Saturation'

  // Saturate: '<S24>/PITCH'
  if (softdrone_pid_B.Conversion3 > softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_PITCH)
  {
    softdrone_pid_B.Conversion3 = softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_PITCH;
  } else if (softdrone_pid_B.Conversion3 <
             -softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_PITCH) {
    softdrone_pid_B.Conversion3 = -softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_PITCH;
  }

  // Gain: '<S33>/Gain' incorporates:
  //   Saturate: '<S24>/PITCH'
  //   Sum: '<S33>/Sum'

  softdrone_pid_B.Gain_h = (softdrone_pid_B.Conversion3 -
    softdrone_pid_B.gyro_data_rotated[1]) * softdrone_pid_P.K_ROLL_AngleRate;

  // DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  if (softdrone_pid_B.LogicalOperator1 ||
      (softdrone_pid_DW.DiscreteTimeIntegrator_PrevResetState_m != 0)) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f =
      softdrone_pid_P.DiscreteTimeIntegrator_IC_f;
  }

  // Sum: '<S33>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  //   Gain: '<S33>/Gain1'
  //   Gain: '<S33>/Gain2'
  //   Gain: '<S33>/Gain3'
  //   Gain: '<S33>/Gain4'

  softdrone_pid_B.Saturation1 = (softdrone_pid_P.Kp_ROLL_AngleRate *
    softdrone_pid_B.Gain_h + softdrone_pid_P.Ki_PITCH_AngleRate *
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f) -
    softdrone_pid_P.K_ROLL_AngleRate * softdrone_pid_B.gyro_data_rotated_g[1] *
    softdrone_pid_P.Kd_PITCH_AngleRate;

  // Saturate: '<S33>/Saturation1'
  if (softdrone_pid_B.Saturation1 > softdrone_pid_P.Saturation1_UpperSat) {
    softdrone_pid_B.Saturation1 = softdrone_pid_P.Saturation1_UpperSat;
  } else if (softdrone_pid_B.Saturation1 < softdrone_pid_P.Saturation1_LowerSat)
  {
    softdrone_pid_B.Saturation1 = softdrone_pid_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S33>/Saturation1'

  // MATLAB Function: '<Root>/MATLAB Function12'
  softdrone_pid_MATLABFunction12(softdrone_pid_B.In1_p.channels[3],
    &softdrone_pid_B.Conversion3);

  // MATLAB Function: '<Root>/MATLAB Function9' incorporates:
  //   Gain: '<Root>/Gain7'

  softdrone_pid_MATLABFunction7(softdrone_pid_P.Gain7_Gain *
    softdrone_pid_B.Conversion3, &softdrone_pid_B.Conversion3);

  // DataTypeConversion: '<Root>/Data Type Conversion3'
  softdrone_pid_B.u0_tmp = floor(softdrone_pid_B.Conversion3);
  if (rtIsNaN(softdrone_pid_B.u0_tmp) || rtIsInf(softdrone_pid_B.u0_tmp)) {
    softdrone_pid_B.u0_tmp = 0.0;
  } else {
    softdrone_pid_B.u0_tmp = fmod(softdrone_pid_B.u0_tmp, 65536.0);
  }

  if (softdrone_pid_B.u0_tmp < 0.0) {
    softdrone_pid_B.i1 = static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-softdrone_pid_B.u0_tmp)));
  } else {
    softdrone_pid_B.i1 = static_cast<uint16_T>(softdrone_pid_B.u0_tmp);
  }

  // MATLAB Function: '<S25>/deadzone4' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'
  //   DataTypeConversion: '<S2>/Conversion10'

  softdrone_pid_deadzone2(static_cast<real_T>(softdrone_pid_B.i1),
    &softdrone_pid_B.Conversion3);

  // Saturate: '<S25>/Saturation7'
  if (softdrone_pid_B.Conversion3 > softdrone_pid_P.Saturation7_UpperSat) {
    softdrone_pid_B.Conversion3 = softdrone_pid_P.Saturation7_UpperSat;
  } else if (softdrone_pid_B.Conversion3 < softdrone_pid_P.Saturation7_LowerSat)
  {
    softdrone_pid_B.Conversion3 = softdrone_pid_P.Saturation7_LowerSat;
  }

  // Sum: '<S24>/Sum' incorporates:
  //   Gain: '<S25>/Gain2'
  //   Gain: '<S25>/deg2rad3'
  //   Gain: '<S29>/Gain'
  //   Gain: '<S29>/Gain1'
  //   MATLAB Function: '<S29>/MATLAB Function'
  //   Product: '<S29>/Product'
  //   Saturate: '<S25>/Saturation7'

  softdrone_pid_B.u0 = (((softdrone_pid_B.quaternion_k[0] * softdrone_pid_B.q2[3]
    + -softdrone_pid_B.quaternion_k[1] * softdrone_pid_B.q2[2]) -
    softdrone_pid_B.q2[1] * -softdrone_pid_B.quaternion_k[2]) +
                        softdrone_pid_B.q2[0] * -softdrone_pid_B.quaternion_k[3])
    * softdrone_pid_B.u0 * softdrone_pid_B.DiscreteTimeIntegrator_g *
    softdrone_pid_B.Saturation1_m + softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_YAW *
    softdrone_pid_B.Conversion3 * softdrone_pid_P.DEG2RAD;

  // Saturate: '<S24>/YAW'
  if (softdrone_pid_B.u0 > softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_YAW) {
    softdrone_pid_B.u0 = softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_YAW;
  } else if (softdrone_pid_B.u0 < -softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_YAW) {
    softdrone_pid_B.u0 = -softdrone_pid_P.MAX_CONTROL_ANGLE_RATE_YAW;
  }

  // Gain: '<S35>/Gain' incorporates:
  //   Saturate: '<S24>/YAW'
  //   Sum: '<S35>/Sum'

  softdrone_pid_B.Conversion3 = (softdrone_pid_B.u0 -
    softdrone_pid_B.gyro_data_rotated[2]) * softdrone_pid_P.K_ROLL_AngleRate;

  // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
  if (softdrone_pid_B.LogicalOperator1 ||
      (softdrone_pid_DW.DiscreteTimeIntegrator_PrevResetState_j != 0)) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i =
      softdrone_pid_P.DiscreteTimeIntegrator_IC_h;
  }

  // Sum: '<S35>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
  //   Gain: '<S35>/Gain1'
  //   Gain: '<S35>/Gain2'
  //   Gain: '<S35>/Gain3'
  //   Gain: '<S35>/Gain4'

  softdrone_pid_B.Saturation1_m = (softdrone_pid_P.Kp_YAW_AngleRate *
    softdrone_pid_B.Conversion3 + softdrone_pid_P.Ki_YAW_AngleRate *
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i) -
    softdrone_pid_P.K_ROLL_AngleRate * softdrone_pid_B.gyro_data_rotated_g[2] *
    softdrone_pid_P.Kd_YAW_AngleRate;

  // Saturate: '<S35>/Saturation1'
  if (softdrone_pid_B.Saturation1_m > softdrone_pid_P.Saturation1_UpperSat_l) {
    softdrone_pid_B.Saturation1_m = softdrone_pid_P.Saturation1_UpperSat_l;
  } else if (softdrone_pid_B.Saturation1_m <
             softdrone_pid_P.Saturation1_LowerSat_g) {
    softdrone_pid_B.Saturation1_m = softdrone_pid_P.Saturation1_LowerSat_g;
  }

  // End of Saturate: '<S35>/Saturation1'

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   DataTypeConversion: '<S2>/Conversion3'

  if (softdrone_pid_B.Dshot2 >= softdrone_pid_P.Switch_Threshold_l) {
    // MATLAB Function: '<S2>/pwm_out2'
    softdrone_pid_B.u0_tmp = softdrone_pid_B.DiscreteTimeIntegrator_f -
      softdrone_pid_B.Saturation;
    softdrone_pid_B.u0 = ((softdrone_pid_B.u0_tmp + softdrone_pid_B.Saturation1)
                          + softdrone_pid_B.Saturation1_m) * 1000.0 + 1000.0;
    softdrone_pid_B.Saturation += softdrone_pid_B.DiscreteTimeIntegrator_f;
    softdrone_pid_B.DiscreteTimeIntegrator_f = ((softdrone_pid_B.Saturation -
      softdrone_pid_B.Saturation1) + softdrone_pid_B.Saturation1_m) * 1000.0 +
      1000.0;
    softdrone_pid_B.Saturation = ((softdrone_pid_B.Saturation +
      softdrone_pid_B.Saturation1) - softdrone_pid_B.Saturation1_m) * 1000.0 +
      1000.0;
    softdrone_pid_B.Saturation1 = ((softdrone_pid_B.u0_tmp -
      softdrone_pid_B.Saturation1) - softdrone_pid_B.Saturation1_m) * 1000.0 +
      1000.0;

    // Saturate: '<S2>/PWM1'
    if (softdrone_pid_B.u0 > softdrone_pid_P.PWM1_UpperSat) {
      softdrone_pid_B.q2[0] = softdrone_pid_P.PWM1_UpperSat;
    } else if (softdrone_pid_B.u0 < softdrone_pid_P.PWM1_LowerSat) {
      softdrone_pid_B.q2[0] = softdrone_pid_P.PWM1_LowerSat;
    } else {
      softdrone_pid_B.q2[0] = softdrone_pid_B.u0;
    }

    // End of Saturate: '<S2>/PWM1'

    // Saturate: '<S2>/PWM2'
    if (softdrone_pid_B.DiscreteTimeIntegrator_f > softdrone_pid_P.PWM2_UpperSat)
    {
      softdrone_pid_B.q2[1] = softdrone_pid_P.PWM2_UpperSat;
    } else if (softdrone_pid_B.DiscreteTimeIntegrator_f <
               softdrone_pid_P.PWM2_LowerSat) {
      softdrone_pid_B.q2[1] = softdrone_pid_P.PWM2_LowerSat;
    } else {
      softdrone_pid_B.q2[1] = softdrone_pid_B.DiscreteTimeIntegrator_f;
    }

    // End of Saturate: '<S2>/PWM2'

    // Saturate: '<S2>/PWM3'
    if (softdrone_pid_B.Saturation > softdrone_pid_P.PWM3_UpperSat) {
      softdrone_pid_B.q2[2] = softdrone_pid_P.PWM3_UpperSat;
    } else if (softdrone_pid_B.Saturation < softdrone_pid_P.PWM3_LowerSat) {
      softdrone_pid_B.q2[2] = softdrone_pid_P.PWM3_LowerSat;
    } else {
      softdrone_pid_B.q2[2] = softdrone_pid_B.Saturation;
    }

    // End of Saturate: '<S2>/PWM3'

    // Saturate: '<S2>/PWM4'
    if (softdrone_pid_B.Saturation1 > softdrone_pid_P.PWM4_UpperSat) {
      softdrone_pid_B.q2[3] = softdrone_pid_P.PWM4_UpperSat;
    } else if (softdrone_pid_B.Saturation1 < softdrone_pid_P.PWM4_LowerSat) {
      softdrone_pid_B.q2[3] = softdrone_pid_P.PWM4_LowerSat;
    } else {
      softdrone_pid_B.q2[3] = softdrone_pid_B.Saturation1;
    }

    // End of Saturate: '<S2>/PWM4'
  } else {
    softdrone_pid_B.q2[0] = softdrone_pid_P.Constant_Value_f[0];
    softdrone_pid_B.q2[1] = softdrone_pid_P.Constant_Value_f[1];
    softdrone_pid_B.q2[2] = softdrone_pid_P.Constant_Value_f[2];
    softdrone_pid_B.q2[3] = softdrone_pid_P.Constant_Value_f[3];
  }

  // End of Switch: '<Root>/Switch'

  // MATLAB Function: '<Root>/MATLAB Function2'
  softdrone_pid_MATLABFunction10(softdrone_pid_B.q2[0], &softdrone_pid_B.Dshot2);

  // Saturate: '<Root>/Dshot1'
  if (softdrone_pid_B.Dshot2 > softdrone_pid_P.Dshot1_UpperSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel1 = softdrone_pid_P.Dshot1_UpperSat;
  } else if (softdrone_pid_B.Dshot2 < softdrone_pid_P.Dshot1_LowerSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel1 = softdrone_pid_P.Dshot1_LowerSat;
  } else {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel1 = softdrone_pid_B.Dshot2;
  }

  // End of Saturate: '<Root>/Dshot1'

  // MATLAB Function: '<Root>/MATLAB Function10'
  softdrone_pid_MATLABFunction10(softdrone_pid_B.q2[1], &softdrone_pid_B.Dshot2);

  // Saturate: '<Root>/Dshot2'
  if (softdrone_pid_B.Dshot2 > softdrone_pid_P.Dshot2_UpperSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel2 = softdrone_pid_P.Dshot2_UpperSat;
  } else if (softdrone_pid_B.Dshot2 < softdrone_pid_P.Dshot2_LowerSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel2 = softdrone_pid_P.Dshot2_LowerSat;
  } else {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel2 = softdrone_pid_B.Dshot2;
  }

  // End of Saturate: '<Root>/Dshot2'

  // MATLAB Function: '<Root>/MATLAB Function3'
  softdrone_pid_MATLABFunction10(softdrone_pid_B.q2[2], &softdrone_pid_B.Dshot2);

  // Saturate: '<Root>/Dshot3'
  if (softdrone_pid_B.Dshot2 > softdrone_pid_P.Dshot3_UpperSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel3 = softdrone_pid_P.Dshot3_UpperSat;
  } else if (softdrone_pid_B.Dshot2 < softdrone_pid_P.Dshot3_LowerSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel3 = softdrone_pid_P.Dshot3_LowerSat;
  } else {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel3 = softdrone_pid_B.Dshot2;
  }

  // End of Saturate: '<Root>/Dshot3'

  // MATLAB Function: '<Root>/MATLAB Function4'
  softdrone_pid_MATLABFunction10(softdrone_pid_B.q2[3], &softdrone_pid_B.Dshot2);

  // Saturate: '<Root>/Dshot4'
  if (softdrone_pid_B.Dshot2 > softdrone_pid_P.Dshot4_UpperSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel4 = softdrone_pid_P.Dshot4_UpperSat;
  } else if (softdrone_pid_B.Dshot2 < softdrone_pid_P.Dshot4_LowerSat) {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel4 = softdrone_pid_P.Dshot4_LowerSat;
  } else {
    // BusCreator: '<Root>/Bus Creator'
    softdrone_pid_B.BusCreator_c.channel4 = softdrone_pid_B.Dshot2;
  }

  // End of Saturate: '<Root>/Dshot4'

  // MATLABSystem: '<S19>/SinkBlock'
  Pub_softdrone_pid_451.publish(&softdrone_pid_B.BusCreator_c);

  // BusCreator: '<S24>/Bus Creator'
  softdrone_pid_B.BusCreator.x = softdrone_pid_B.gyro_data_rotated_g[0];
  softdrone_pid_B.BusCreator.y = softdrone_pid_B.gyro_data_rotated_g[1];
  softdrone_pid_B.BusCreator.z = softdrone_pid_B.gyro_data_rotated_g[2];

  // MATLABSystem: '<S36>/SinkBlock'
  Pub_softdrone_pid_658.publish(&softdrone_pid_B.BusCreator);

  // BusCreator: '<Root>/Bus Creator1' incorporates:
  //   Gain: '<Root>/Gain3'
  //   Gain: '<Root>/Gain4'
  //   Gain: '<Root>/Gain5'
  //   MATLAB Function: '<Root>/MATLAB Function'

  softdrone_pid_B.BusCreator.x = softdrone_pid_P.Gain3_Gain * softdrone_pid_B.qy;
  softdrone_pid_B.BusCreator.y = softdrone_pid_P.Gain4_Gain * softdrone_pid_B.qx;
  softdrone_pid_B.BusCreator.z = softdrone_pid_P.Gain5_Gain * softdrone_pid_B.tr;

  // MATLABSystem: '<S20>/SinkBlock'
  Pub_softdrone_pid_597.publish(&softdrone_pid_B.BusCreator);

  // BusCreator: '<Root>/Bus Creator2'
  softdrone_pid_B.BusCreator.x = softdrone_pid_B.gyro_data_rotated[0];
  softdrone_pid_B.BusCreator.y = softdrone_pid_B.gyro_data_rotated[1];
  softdrone_pid_B.BusCreator.z = softdrone_pid_B.gyro_data_rotated[2];

  // MATLABSystem: '<S21>/SinkBlock'
  Pub_softdrone_pid_609.publish(&softdrone_pid_B.BusCreator);

  // Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE +=
    softdrone_pid_P.DiscreteTimeIntegrator_gainval * softdrone_pid_B.S;
  if (softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE >
      softdrone_pid_P.Saturation_I_RP_Max) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE =
      softdrone_pid_P.Saturation_I_RP_Max;
  } else if (softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE <
             softdrone_pid_P.Saturation_I_RP_Min) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE =
      softdrone_pid_P.Saturation_I_RP_Min;
  }

  softdrone_pid_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
    (softdrone_pid_B.LogicalOperator1);

  // Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'

  softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f +=
    softdrone_pid_P.DiscreteTimeIntegrator_gainval_d * softdrone_pid_B.Gain_h;
  if (softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f >
      softdrone_pid_P.Saturation_I_RP_Max) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f =
      softdrone_pid_P.Saturation_I_RP_Max;
  } else if (softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f <
             softdrone_pid_P.Saturation_I_RP_Min) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f =
      softdrone_pid_P.Saturation_I_RP_Min;
  }

  softdrone_pid_DW.DiscreteTimeIntegrator_PrevResetState_m = static_cast<int8_T>
    (softdrone_pid_B.LogicalOperator1);

  // End of Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'

  softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i +=
    softdrone_pid_P.DiscreteTimeIntegrator_gainval_g *
    softdrone_pid_B.Conversion3;
  if (softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i >
      softdrone_pid_P.Saturation_I_RP_Max) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i =
      softdrone_pid_P.Saturation_I_RP_Max;
  } else if (softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i <
             softdrone_pid_P.Saturation_I_RP_Min) {
    softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i =
      softdrone_pid_P.Saturation_I_RP_Min;
  }

  softdrone_pid_DW.DiscreteTimeIntegrator_PrevResetState_j = static_cast<int8_T>
    (softdrone_pid_B.LogicalOperator1);

  // End of Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
}

// Model initialize function
void softdrone_pid_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' 
  softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE =
    softdrone_pid_P.DiscreteTimeIntegrator_IC;

  // InitializeConditions for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' 
  softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_f =
    softdrone_pid_P.DiscreteTimeIntegrator_IC_f;

  // InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' 
  softdrone_pid_DW.DiscreteTimeIntegrator_DSTATE_i =
    softdrone_pid_P.DiscreteTimeIntegrator_IC_h;

  // SystemInitialize for Enabled SubSystem: '<S22>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S47>/In1' incorporates:
  //   Outport: '<S47>/Out1'

  softdrone_pid_B.In1_p = softdrone_pid_P.Out1_Y0_p;

  // End of SystemInitialize for SubSystem: '<S22>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S48>/In1' incorporates:
  //   Outport: '<S48>/Out1'

  softdrone_pid_B.In1 = softdrone_pid_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S37>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S40>/In1' incorporates:
  //   Outport: '<S40>/Out1'

  softdrone_pid_B.In1_a = softdrone_pid_P.Out1_Y0_l;

  // End of SystemInitialize for SubSystem: '<S37>/Enabled Subsystem'

  // Start for MATLABSystem: '<S22>/SourceBlock'
  softdrone_pid_SystemCore_setup_fklop(&softdrone_pid_DW.obj_o);

  // Start for MATLABSystem: '<S23>/SourceBlock'
  softdrone_pid_SystemCore_setup_fklopg(&softdrone_pid_DW.obj_j);

  // Start for MATLABSystem: '<S37>/SourceBlock'
  softdrone_pid_SystemCore_setup_f(&softdrone_pid_DW.obj_c);

  // Start for MATLABSystem: '<S19>/SinkBlock'
  softdrone_pid_SystemCore_setup_fk(&softdrone_pid_DW.obj_m);

  // Start for MATLABSystem: '<S36>/SinkBlock'
  softdrone_pid_SystemCore_setup(&softdrone_pid_DW.obj_g3);

  // Start for MATLABSystem: '<S20>/SinkBlock'
  softdrone_pid_SystemCore_setup_fkl(&softdrone_pid_DW.obj_g);

  // Start for MATLABSystem: '<S21>/SinkBlock'
  softdrone_pid_SystemCore_setup_fklo(&softdrone_pid_DW.obj);
}

// Model terminate function
void softdrone_pid_terminate(void)
{
  // Terminate for MATLABSystem: '<S22>/SourceBlock'
  if (!softdrone_pid_DW.obj_o.matlabCodegenIsDeleted) {
    softdrone_pid_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S22>/SourceBlock'

  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!softdrone_pid_DW.obj_j.matlabCodegenIsDeleted) {
    softdrone_pid_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'

  // Terminate for MATLABSystem: '<S37>/SourceBlock'
  if (!softdrone_pid_DW.obj_c.matlabCodegenIsDeleted) {
    softdrone_pid_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S37>/SourceBlock'

  // Terminate for MATLABSystem: '<S19>/SinkBlock'
  if (!softdrone_pid_DW.obj_m.matlabCodegenIsDeleted) {
    softdrone_pid_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/SinkBlock'

  // Terminate for MATLABSystem: '<S36>/SinkBlock'
  if (!softdrone_pid_DW.obj_g3.matlabCodegenIsDeleted) {
    softdrone_pid_DW.obj_g3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S36>/SinkBlock'

  // Terminate for MATLABSystem: '<S20>/SinkBlock'
  if (!softdrone_pid_DW.obj_g.matlabCodegenIsDeleted) {
    softdrone_pid_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S20>/SinkBlock'

  // Terminate for MATLABSystem: '<S21>/SinkBlock'
  if (!softdrone_pid_DW.obj.matlabCodegenIsDeleted) {
    softdrone_pid_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
