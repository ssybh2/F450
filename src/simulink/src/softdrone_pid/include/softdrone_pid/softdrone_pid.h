//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: softdrone_pid.h
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
#ifndef RTW_HEADER_softdrone_pid_h_
#define RTW_HEADER_softdrone_pid_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "softdrone_pid_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_softdrone_pid_T {
  SL_Bus_sensor_msgs_Imu In1;          // '<S48>/In1'
  SL_Bus_sensor_msgs_Imu b_varargout_2;
  SL_Bus_custom_msgs_ReadSBUSRC In1_p; // '<S47>/In1'
  SL_Bus_custom_msgs_ReadSBUSRC b_varargout_2_m;
  real_T R[9];
  real_T dv[9];
  real_T R_tmp[9];
  real_T q2[4];
  real_T quaternion_k[4];              // '<S24>/Eurle2quat'
  SL_Bus_geometry_msgs_Vector3 In1_a;  // '<S40>/In1'
  SL_Bus_geometry_msgs_Vector3 BusCreator;// '<S24>/Bus Creator'
  real_T gyro_data_rotated[3];         // '<Root>/MATLAB Function1'
  real_T gyro_data_rotated_g[3];       // '<S24>/MATLAB Function1'
  int8_T R_tmp_c[9];
  real_T tr;
  real_T S;
  real_T qx;
  real_T qy;
  real_T DiscreteTimeIntegrator_f;     // '<S35>/Discrete-Time Integrator'
  real_T Conversion3;                  // '<S2>/Conversion3'
  real_T DiscreteTimeIntegrator_g;     // '<S34>/Discrete-Time Integrator'
  real_T Saturation;                   // '<S34>/Saturation'
  real_T Gain_h;                       // '<S33>/Gain'
  real_T Saturation1;                  // '<S33>/Saturation1'
  real_T Saturation1_m;                // '<S35>/Saturation1'
  real_T u0;
  real_T u0_tmp;
  SL_Bus_custom_msgs_WriteOnBoardPWM BusCreator_c;// '<Root>/Bus Creator'
  int32_T u;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  uint16_T Dshot2;                     // '<Root>/Dshot2'
  int8_T R_tmp_k;
  int8_T R_tmp_cx;
  int8_T R_tmp_b;
  boolean_T b_varargout_1;
  boolean_T LogicalOperator1;          // '<S2>/Logical Operator1'
};

// Block states (default storage) for system '<Root>'
struct DW_softdrone_pid_T {
  ros_slros2_internal_block_Publisher_softdrone_pid_T obj;// '<S21>/SinkBlock'
  ros_slros2_internal_block_Publisher_softdrone_pid_T obj_g;// '<S20>/SinkBlock' 
  ros_slros2_internal_block_Publisher_softdrone_pid_T obj_m;// '<S19>/SinkBlock' 
  ros_slros2_internal_block_Publisher_softdrone_pid_T obj_g3;// '<S36>/SinkBlock' 
  ros_slros2_internal_block_Subscriber_softdrone_pid_T obj_j;// '<S23>/SourceBlock' 
  ros_slros2_internal_block_Subscriber_softdrone_pid_T obj_o;// '<S22>/SourceBlock' 
  ros_slros2_internal_block_Subscriber_softdrone_pid_T obj_c;// '<S37>/SourceBlock' 
  real_T DiscreteTimeIntegrator_DSTATE;// '<S34>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_f;// '<S33>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_i;// '<S35>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevResetState;// '<S34>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_m;// '<S33>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_j;// '<S35>/Discrete-Time Integrator' 
};

// Parameters (default storage)
struct P_softdrone_pid_T_ {
  real_T DEG2RAD;                      // Variable: DEG2RAD
                                          //  Referenced by:
                                          //    '<S25>/deg2rad1'
                                          //    '<S25>/deg2rad2'
                                          //    '<S25>/deg2rad3'

  real_T K_ROLL_AngleRate;             // Variable: K_ROLL_AngleRate
                                          //  Referenced by:
                                          //    '<S33>/Gain'
                                          //    '<S33>/Gain1'
                                          //    '<S34>/Gain'
                                          //    '<S34>/Gain1'
                                          //    '<S35>/Gain'
                                          //    '<S35>/Gain1'

  real_T Kd_PITCH_AngleRate;           // Variable: Kd_PITCH_AngleRate
                                          //  Referenced by: '<S33>/Gain2'

  real_T Kd_ROLL_AngleRate;            // Variable: Kd_ROLL_AngleRate
                                          //  Referenced by: '<S34>/Gain2'

  real_T Kd_YAW_AngleRate;             // Variable: Kd_YAW_AngleRate
                                          //  Referenced by: '<S35>/Gain2'

  real_T Ki_PITCH_AngleRate;           // Variable: Ki_PITCH_AngleRate
                                          //  Referenced by: '<S33>/Gain4'

  real_T Ki_ROLL_AngleRate;            // Variable: Ki_ROLL_AngleRate
                                          //  Referenced by: '<S34>/Gain4'

  real_T Ki_YAW_AngleRate;             // Variable: Ki_YAW_AngleRate
                                          //  Referenced by: '<S35>/Gain4'

  real_T Kp_ANGLE;                     // Variable: Kp_ANGLE
                                          //  Referenced by: '<S29>/Gain'

  real_T Kp_ROLL_AngleRate;            // Variable: Kp_ROLL_AngleRate
                                          //  Referenced by:
                                          //    '<S33>/Gain3'
                                          //    '<S34>/Gain3'

  real_T Kp_YAW_AngleRate;             // Variable: Kp_YAW_AngleRate
                                          //  Referenced by: '<S35>/Gain3'

  real_T MAX_CONTROL_ANGLE_PITCH;      // Variable: MAX_CONTROL_ANGLE_PITCH
                                          //  Referenced by: '<S25>/Gain3'

  real_T MAX_CONTROL_ANGLE_RATE_PITCH; // Variable: MAX_CONTROL_ANGLE_RATE_PITCH
                                          //  Referenced by: '<S24>/PITCH'

  real_T MAX_CONTROL_ANGLE_RATE_ROLL;  // Variable: MAX_CONTROL_ANGLE_RATE_ROLL
                                          //  Referenced by: '<S24>/ROLL'

  real_T MAX_CONTROL_ANGLE_RATE_YAW;   // Variable: MAX_CONTROL_ANGLE_RATE_YAW
                                          //  Referenced by:
                                          //    '<S24>/YAW'
                                          //    '<S25>/Gain2'

  real_T MAX_CONTROL_ANGLE_ROLL;       // Variable: MAX_CONTROL_ANGLE_ROLL
                                          //  Referenced by: '<S25>/Gain1'

  real_T Saturation_I_RP_Max;          // Variable: Saturation_I_RP_Max
                                          //  Referenced by:
                                          //    '<S33>/Discrete-Time Integrator'
                                          //    '<S34>/Discrete-Time Integrator'
                                          //    '<S35>/Discrete-Time Integrator'

  real_T Saturation_I_RP_Min;          // Variable: Saturation_I_RP_Min
                                          //  Referenced by:
                                          //    '<S33>/Discrete-Time Integrator'
                                          //    '<S34>/Discrete-Time Integrator'
                                          //    '<S35>/Discrete-Time Integrator'

  real_T THR_HOVER;                    // Variable: THR_HOVER
                                          //  Referenced by: '<S25>/thr_hover '

  real_T TIME_Constant;                // Variable: TIME_Constant
                                          //  Referenced by: '<S29>/Gain1'

  real_T CompareToConstant3_const;   // Mask Parameter: CompareToConstant3_const
                                        //  Referenced by: '<S46>/Constant'

  uint16_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S1>/Constant'

  SL_Bus_sensor_msgs_Imu Out1_Y0;      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S48>/Out1'

  SL_Bus_sensor_msgs_Imu Constant_Value;// Computed Parameter: Constant_Value
                                           //  Referenced by: '<S23>/Constant'

  SL_Bus_custom_msgs_ReadSBUSRC Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                             //  Referenced by: '<S47>/Out1'

  SL_Bus_custom_msgs_ReadSBUSRC Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                    //  Referenced by: '<S22>/Constant'

  SL_Bus_geometry_msgs_Vector3 Out1_Y0_l;// Computed Parameter: Out1_Y0_l
                                            //  Referenced by: '<S40>/Out1'

  SL_Bus_geometry_msgs_Vector3 Constant_Value_pd;// Computed Parameter: Constant_Value_pd
                                                    //  Referenced by: '<S37>/Constant'

  real_T Constant1_Value;              // Expression: 1
                                          //  Referenced by: '<S29>/Constant1'

  real_T Constant_Value_pp;            // Expression: -1
                                          //  Referenced by: '<S29>/Constant'

  real_T PWM1_UpperSat;                // Expression: 2000
                                          //  Referenced by: '<S2>/PWM1'

  real_T PWM1_LowerSat;                // Expression: 1200
                                          //  Referenced by: '<S2>/PWM1'

  real_T PWM2_UpperSat;                // Expression: 2000
                                          //  Referenced by: '<S2>/PWM2'

  real_T PWM2_LowerSat;                // Expression: 1200
                                          //  Referenced by: '<S2>/PWM2'

  real_T PWM3_UpperSat;                // Expression: 2000
                                          //  Referenced by: '<S2>/PWM3'

  real_T PWM3_LowerSat;                // Expression: 1200
                                          //  Referenced by: '<S2>/PWM3'

  real_T PWM4_UpperSat;                // Expression: 2000
                                          //  Referenced by: '<S2>/PWM4'

  real_T PWM4_LowerSat;                // Expression: 1200
                                          //  Referenced by: '<S2>/PWM4'

  real_T Constant_Value_f[4];          // Expression: [1000,1000,1000,1000]
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant_Value_d;             // Expression: 1
                                          //  Referenced by: '<S25>/Constant'

  real_T Gain_Gain;                    // Expression: 0.5
                                          //  Referenced by: '<S25>/Gain'

  real_T Saturation10_UpperSat;        // Expression: 1
                                          //  Referenced by: '<S25>/Saturation10'

  real_T Saturation10_LowerSat;        // Expression: 0
                                          //  Referenced by: '<S25>/Saturation10'

  real_T Gain8_Gain;                   // Expression: -1
                                          //  Referenced by: '<Root>/Gain8'

  real_T Saturation9_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S25>/Saturation9'

  real_T Saturation9_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S25>/Saturation9'

  real_T Gain6_Gain;                   // Expression: -1
                                          //  Referenced by: '<Root>/Gain6'

  real_T Saturation8_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S25>/Saturation8'

  real_T Saturation8_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S25>/Saturation8'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S29>/Switch'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S34>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S34>/Discrete-Time Integrator'

  real_T Saturation_UpperSat;          // Expression: 1
                                          //  Referenced by: '<S34>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -1
                                          //  Referenced by: '<S34>/Saturation'

  real_T DiscreteTimeIntegrator_gainval_d;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_d
                            //  Referenced by: '<S33>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_f;  // Expression: 0
                                          //  Referenced by: '<S33>/Discrete-Time Integrator'

  real_T Saturation1_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S33>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S33>/Saturation1'

  real_T Gain7_Gain;                   // Expression: -1
                                          //  Referenced by: '<Root>/Gain7'

  real_T Saturation7_UpperSat;         // Expression: 1
                                          //  Referenced by: '<S25>/Saturation7'

  real_T Saturation7_LowerSat;         // Expression: -1
                                          //  Referenced by: '<S25>/Saturation7'

  real_T DiscreteTimeIntegrator_gainval_g;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_g
                            //  Referenced by: '<S35>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_h;  // Expression: 0
                                          //  Referenced by: '<S35>/Discrete-Time Integrator'

  real_T Saturation1_UpperSat_l;       // Expression: 1
                                          //  Referenced by: '<S35>/Saturation1'

  real_T Saturation1_LowerSat_g;       // Expression: -1
                                          //  Referenced by: '<S35>/Saturation1'

  real_T Switch_Threshold_l;           // Expression: 1
                                          //  Referenced by: '<Root>/Switch'

  real_T Gain3_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<Root>/Gain3'

  real_T Gain4_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<Root>/Gain4'

  real_T Gain5_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<Root>/Gain5'

  uint16_T Dshot1_UpperSat;            // Computed Parameter: Dshot1_UpperSat
                                          //  Referenced by: '<Root>/Dshot1'

  uint16_T Dshot1_LowerSat;            // Computed Parameter: Dshot1_LowerSat
                                          //  Referenced by: '<Root>/Dshot1'

  uint16_T Dshot2_UpperSat;            // Computed Parameter: Dshot2_UpperSat
                                          //  Referenced by: '<Root>/Dshot2'

  uint16_T Dshot2_LowerSat;            // Computed Parameter: Dshot2_LowerSat
                                          //  Referenced by: '<Root>/Dshot2'

  uint16_T Dshot3_UpperSat;            // Computed Parameter: Dshot3_UpperSat
                                          //  Referenced by: '<Root>/Dshot3'

  uint16_T Dshot3_LowerSat;            // Computed Parameter: Dshot3_LowerSat
                                          //  Referenced by: '<Root>/Dshot3'

  uint16_T Dshot4_UpperSat;            // Computed Parameter: Dshot4_UpperSat
                                          //  Referenced by: '<Root>/Dshot4'

  uint16_T Dshot4_LowerSat;            // Computed Parameter: Dshot4_LowerSat
                                          //  Referenced by: '<Root>/Dshot4'

};

// Real-time Model Data Structure
struct tag_RTM_softdrone_pid_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_softdrone_pid_T softdrone_pid_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_softdrone_pid_T softdrone_pid_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_softdrone_pid_T softdrone_pid_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void softdrone_pid_initialize(void);
  extern void softdrone_pid_step(void);
  extern void softdrone_pid_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_softdrone_pid_T *const softdrone_pid_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<Root>/Display1' : Unused code path elimination
//  Block '<Root>/Display10' : Unused code path elimination
//  Block '<Root>/Display11' : Unused code path elimination
//  Block '<Root>/Display12' : Unused code path elimination
//  Block '<Root>/Display13' : Unused code path elimination
//  Block '<Root>/Display2' : Unused code path elimination
//  Block '<Root>/Display3' : Unused code path elimination
//  Block '<Root>/Display4' : Unused code path elimination
//  Block '<Root>/Display5' : Unused code path elimination
//  Block '<Root>/Display6' : Unused code path elimination
//  Block '<Root>/Display7' : Unused code path elimination
//  Block '<Root>/Display8' : Unused code path elimination
//  Block '<Root>/Display9' : Unused code path elimination
//  Block '<Root>/Gain' : Unused code path elimination
//  Block '<Root>/Gain1' : Unused code path elimination
//  Block '<Root>/Gain2' : Unused code path elimination
//  Block '<S24>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S24>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S24>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S2>/Conversion1' : Eliminate redundant data type conversion
//  Block '<S2>/Conversion11' : Eliminate redundant data type conversion
//  Block '<S2>/Conversion2' : Eliminate redundant data type conversion
//  Block '<S2>/Conversion4' : Eliminate redundant data type conversion
//  Block '<S2>/Conversion5' : Eliminate redundant data type conversion
//  Block '<S2>/Conversion6' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion13' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion14' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion9' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'softdrone_pid'
//  '<S1>'   : 'softdrone_pid/Compare To Constant'
//  '<S2>'   : 'softdrone_pid/Control System'
//  '<S3>'   : 'softdrone_pid/MATLAB Function'
//  '<S4>'   : 'softdrone_pid/MATLAB Function1'
//  '<S5>'   : 'softdrone_pid/MATLAB Function10'
//  '<S6>'   : 'softdrone_pid/MATLAB Function11'
//  '<S7>'   : 'softdrone_pid/MATLAB Function12'
//  '<S8>'   : 'softdrone_pid/MATLAB Function13'
//  '<S9>'   : 'softdrone_pid/MATLAB Function14'
//  '<S10>'  : 'softdrone_pid/MATLAB Function15'
//  '<S11>'  : 'softdrone_pid/MATLAB Function2'
//  '<S12>'  : 'softdrone_pid/MATLAB Function3'
//  '<S13>'  : 'softdrone_pid/MATLAB Function4'
//  '<S14>'  : 'softdrone_pid/MATLAB Function5'
//  '<S15>'  : 'softdrone_pid/MATLAB Function6'
//  '<S16>'  : 'softdrone_pid/MATLAB Function7'
//  '<S17>'  : 'softdrone_pid/MATLAB Function8'
//  '<S18>'  : 'softdrone_pid/MATLAB Function9'
//  '<S19>'  : 'softdrone_pid/Publish'
//  '<S20>'  : 'softdrone_pid/Publish1'
//  '<S21>'  : 'softdrone_pid/Publish2'
//  '<S22>'  : 'softdrone_pid/Subscribe'
//  '<S23>'  : 'softdrone_pid/Subscribe1'
//  '<S24>'  : 'softdrone_pid/Control System/AttitudeControl'
//  '<S25>'  : 'softdrone_pid/Control System/InputConditioning'
//  '<S26>'  : 'softdrone_pid/Control System/LED '
//  '<S27>'  : 'softdrone_pid/Control System/pwm_out2'
//  '<S28>'  : 'softdrone_pid/Control System/reset_i'
//  '<S29>'  : 'softdrone_pid/Control System/AttitudeControl/Angle controller'
//  '<S30>'  : 'softdrone_pid/Control System/AttitudeControl/Eurle2quat'
//  '<S31>'  : 'softdrone_pid/Control System/AttitudeControl/Eurle2quat1'
//  '<S32>'  : 'softdrone_pid/Control System/AttitudeControl/MATLAB Function1'
//  '<S33>'  : 'softdrone_pid/Control System/AttitudeControl/PID_pitchRate'
//  '<S34>'  : 'softdrone_pid/Control System/AttitudeControl/PID_rollRate'
//  '<S35>'  : 'softdrone_pid/Control System/AttitudeControl/PID_yawRate'
//  '<S36>'  : 'softdrone_pid/Control System/AttitudeControl/Publish'
//  '<S37>'  : 'softdrone_pid/Control System/AttitudeControl/Subscribe'
//  '<S38>'  : 'softdrone_pid/Control System/AttitudeControl/Angle controller/MATLAB Function'
//  '<S39>'  : 'softdrone_pid/Control System/AttitudeControl/Angle controller/MATLAB Function1'
//  '<S40>'  : 'softdrone_pid/Control System/AttitudeControl/Subscribe/Enabled Subsystem'
//  '<S41>'  : 'softdrone_pid/Control System/InputConditioning/deadzone1'
//  '<S42>'  : 'softdrone_pid/Control System/InputConditioning/deadzone2'
//  '<S43>'  : 'softdrone_pid/Control System/InputConditioning/deadzone3'
//  '<S44>'  : 'softdrone_pid/Control System/InputConditioning/deadzone4'
//  '<S45>'  : 'softdrone_pid/Control System/InputConditioning/f1'
//  '<S46>'  : 'softdrone_pid/Control System/reset_i/Compare To Constant3'
//  '<S47>'  : 'softdrone_pid/Subscribe/Enabled Subsystem'
//  '<S48>'  : 'softdrone_pid/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_softdrone_pid_h_

//
// File trailer for generated code.
//
// [EOF]
//
