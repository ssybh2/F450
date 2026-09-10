//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: softdrone_pid_data.cpp
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

// Block parameters (default storage)
P_softdrone_pid_T softdrone_pid_P = {
  // Variable: DEG2RAD
  //  Referenced by:
  //    '<S25>/deg2rad1'
  //    '<S25>/deg2rad2'
  //    '<S25>/deg2rad3'

  0.0174533,

  // Variable: K_ROLL_AngleRate
  //  Referenced by:
  //    '<S33>/Gain'
  //    '<S33>/Gain1'
  //    '<S34>/Gain'
  //    '<S34>/Gain1'
  //    '<S35>/Gain'
  //    '<S35>/Gain1'

  1.0,

  // Variable: Kd_PITCH_AngleRate
  //  Referenced by: '<S33>/Gain2'

  0.003,

  // Variable: Kd_ROLL_AngleRate
  //  Referenced by: '<S34>/Gain2'

  0.003,

  // Variable: Kd_YAW_AngleRate
  //  Referenced by: '<S35>/Gain2'

  0.01,

  // Variable: Ki_PITCH_AngleRate
  //  Referenced by: '<S33>/Gain4'

  0.002,

  // Variable: Ki_ROLL_AngleRate
  //  Referenced by: '<S34>/Gain4'

  0.002,

  // Variable: Ki_YAW_AngleRate
  //  Referenced by: '<S35>/Gain4'

  0.0,

  // Variable: Kp_ANGLE
  //  Referenced by: '<S29>/Gain'

  1.0,

  // Variable: Kp_ROLL_AngleRate
  //  Referenced by:
  //    '<S33>/Gain3'
  //    '<S34>/Gain3'

  0.122,

  // Variable: Kp_YAW_AngleRate
  //  Referenced by: '<S35>/Gain3'

  1.0,

  // Variable: MAX_CONTROL_ANGLE_PITCH
  //  Referenced by: '<S25>/Gain3'

  35.0,

  // Variable: MAX_CONTROL_ANGLE_RATE_PITCH
  //  Referenced by: '<S24>/PITCH'

  350.0,

  // Variable: MAX_CONTROL_ANGLE_RATE_ROLL
  //  Referenced by: '<S24>/ROLL'

  350.0,

  // Variable: MAX_CONTROL_ANGLE_RATE_YAW
  //  Referenced by:
  //    '<S24>/YAW'
  //    '<S25>/Gain2'

  250.0,

  // Variable: MAX_CONTROL_ANGLE_ROLL
  //  Referenced by: '<S25>/Gain1'

  35.0,

  // Variable: Saturation_I_RP_Max
  //  Referenced by:
  //    '<S33>/Discrete-Time Integrator'
  //    '<S34>/Discrete-Time Integrator'
  //    '<S35>/Discrete-Time Integrator'

  0.3,

  // Variable: Saturation_I_RP_Min
  //  Referenced by:
  //    '<S33>/Discrete-Time Integrator'
  //    '<S34>/Discrete-Time Integrator'
  //    '<S35>/Discrete-Time Integrator'

  -0.3,

  // Variable: THR_HOVER
  //  Referenced by: '<S25>/thr_hover '

  0.609,

  // Variable: TIME_Constant
  //  Referenced by: '<S29>/Gain1'

  0.1,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S46>/Constant'

  0.2,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S1>/Constant'

  1500U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S48>/Out1'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      0.0,                             // x
      0.0,                             // y
      0.0,                             // z
      0.0                              // w
    },                                 // orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // orientation_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // angular_velocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // angular_velocity_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // linear_acceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // linear_acceleration_covariance
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S23>/Constant'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header

    {
      0.0,                             // x
      0.0,                             // y
      0.0,                             // z
      0.0                              // w
    },                                 // orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // orientation_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // angular_velocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // angular_velocity_covariance

    {
      0.0,                             // x
      0.0,                             // y
      0.0                              // z
    },                                 // linear_acceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // linear_acceleration_covariance
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S47>/Out1'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header
    0U,                                // online

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // channels

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // channels_SL_Info
    0U,                                // ch17
    0U,                                // ch18
    0U,                                // fail_safe
    0U                                 // frame_lost
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S22>/Constant'

  {
    {
      {
        0,                             // sec
        0U                             // nanosec
      },                               // stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // frame_id

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // frame_id_SL_Info
    },                                 // header
    0U,                                // online

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // channels

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // channels_SL_Info
    0U,                                // ch17
    0U,                                // ch18
    0U,                                // fail_safe
    0U                                 // frame_lost
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S40>/Out1'

  {
    0.0,                               // x
    0.0,                               // y
    0.0                                // z
  },

  // Computed Parameter: Constant_Value_pd
  //  Referenced by: '<S37>/Constant'

  {
    0.0,                               // x
    0.0,                               // y
    0.0                                // z
  },

  // Expression: 1
  //  Referenced by: '<S29>/Constant1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S29>/Constant'

  -1.0,

  // Expression: 2000
  //  Referenced by: '<S2>/PWM1'

  2000.0,

  // Expression: 1200
  //  Referenced by: '<S2>/PWM1'

  1200.0,

  // Expression: 2000
  //  Referenced by: '<S2>/PWM2'

  2000.0,

  // Expression: 1200
  //  Referenced by: '<S2>/PWM2'

  1200.0,

  // Expression: 2000
  //  Referenced by: '<S2>/PWM3'

  2000.0,

  // Expression: 1200
  //  Referenced by: '<S2>/PWM3'

  1200.0,

  // Expression: 2000
  //  Referenced by: '<S2>/PWM4'

  2000.0,

  // Expression: 1200
  //  Referenced by: '<S2>/PWM4'

  1200.0,

  // Expression: [1000,1000,1000,1000]
  //  Referenced by: '<Root>/Constant'

  { 1000.0, 1000.0, 1000.0, 1000.0 },

  // Expression: 1
  //  Referenced by: '<S25>/Constant'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S25>/Gain'

  0.5,

  // Expression: 1
  //  Referenced by: '<S25>/Saturation10'

  1.0,

  // Expression: 0
  //  Referenced by: '<S25>/Saturation10'

  0.0,

  // Expression: -1
  //  Referenced by: '<Root>/Gain8'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S25>/Saturation9'

  1.0,

  // Expression: -1
  //  Referenced by: '<S25>/Saturation9'

  -1.0,

  // Expression: -1
  //  Referenced by: '<Root>/Gain6'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S25>/Saturation8'

  1.0,

  // Expression: -1
  //  Referenced by: '<S25>/Saturation8'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S29>/Switch'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S34>/Discrete-Time Integrator'

  0.001,

  // Expression: 0
  //  Referenced by: '<S34>/Discrete-Time Integrator'

  0.0,

  // Expression: 1
  //  Referenced by: '<S34>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S34>/Saturation'

  -1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval_d
  //  Referenced by: '<S33>/Discrete-Time Integrator'

  0.001,

  // Expression: 0
  //  Referenced by: '<S33>/Discrete-Time Integrator'

  0.0,

  // Expression: 1
  //  Referenced by: '<S33>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S33>/Saturation1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<Root>/Gain7'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S25>/Saturation7'

  1.0,

  // Expression: -1
  //  Referenced by: '<S25>/Saturation7'

  -1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval_g
  //  Referenced by: '<S35>/Discrete-Time Integrator'

  0.001,

  // Expression: 0
  //  Referenced by: '<S35>/Discrete-Time Integrator'

  0.0,

  // Expression: 1
  //  Referenced by: '<S35>/Saturation1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S35>/Saturation1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Switch'

  1.0,

  // Expression: 180/pi
  //  Referenced by: '<Root>/Gain3'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<Root>/Gain4'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<Root>/Gain5'

  57.295779513082323,

  // Computed Parameter: Dshot1_UpperSat
  //  Referenced by: '<Root>/Dshot1'

  2000U,

  // Computed Parameter: Dshot1_LowerSat
  //  Referenced by: '<Root>/Dshot1'

  1000U,

  // Computed Parameter: Dshot2_UpperSat
  //  Referenced by: '<Root>/Dshot2'

  2000U,

  // Computed Parameter: Dshot2_LowerSat
  //  Referenced by: '<Root>/Dshot2'

  1000U,

  // Computed Parameter: Dshot3_UpperSat
  //  Referenced by: '<Root>/Dshot3'

  2000U,

  // Computed Parameter: Dshot3_LowerSat
  //  Referenced by: '<Root>/Dshot3'

  1000U,

  // Computed Parameter: Dshot4_UpperSat
  //  Referenced by: '<Root>/Dshot4'

  2000U,

  // Computed Parameter: Dshot4_LowerSat
  //  Referenced by: '<Root>/Dshot4'

  1000U
};

//
// File trailer for generated code.
//
// [EOF]
//
