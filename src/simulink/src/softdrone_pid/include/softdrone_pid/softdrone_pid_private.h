//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: softdrone_pid_private.h
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
#ifndef RTW_HEADER_softdrone_pid_private_h_
#define RTW_HEADER_softdrone_pid_private_h_
#include "rtwtypes.h"
#include "softdrone_pid_types.h"
#include "softdrone_pid.h"

extern real_T rt_roundd_snf(real_T u);
extern void softdrone_pid_Eurle2quat(real_T rtu_roll, real_T rtu_pitch, real_T
  rtu_yaw, real_T rty_quaternion[4]);
extern void softdrone_pid_deadzone2(real_T rtu_u, real_T *rty_y);
extern void softdrone_pid_MATLABFunction10(real_T rtu_u, uint16_T *rty_y);
extern void softdrone_pid_MATLABFunction12(uint16_T rtu_u, real_T *rty_y);
extern void softdrone_pid_MATLABFunction7(real_T rtu_u, real_T *rty_y);

#endif                                 // RTW_HEADER_softdrone_pid_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
