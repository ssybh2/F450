%%%  PositionControl_HIL
clear

Init

%Constant value
RAD2DEG = 57.2957795;
DEG2RAD = 0.0174533;
%throttle when UAV is hovering
THR_HOVER = 0.609;

%% control parameter
% attitude PID parameters
Kp_ANGLE = 1;
Kp_PITCH_ANGLE = 1.8;
K_PITCH_AngleRate = 0.9;
Kp_PITCH_AngleRate = 0.04;
Ki_PITCH_AngleRate = 0.000;
Kd_PITCH_AngleRate = 0.002;
Kp_ROLL_ANGLE = 1.8;
K_ROLL_AngleRate = 0.9;
Kp_ROLL_AngleRate = 0.065;
Ki_ROLL_AngleRate = 0.000;
Kd_ROLL_AngleRate = 0.003;

Kp_YAW_ANGLE = 2.0;
K_YAW_AngleRate = 1;
Kp_YAW_AngleRate = 0.5;
Ki_YAW_AngleRate = 0.3;
Kd_YAW_AngleRate = 0.01;
% position PID parameters
Kpxp = 1.0;
Kpyp = 1.0;
Kpzp = 4.0;
Kvxp = 2.5; Kvxi = 0.4; Kvxd = 0.01;
Kvyp = 2.5; Kvyi = 0.4; Kvyd = 0.01;
Kvzp = 0.45; Kvzi = 0.01; Kvzd = 0.005;
% integral saturation
Saturation_I_RP_Max = 0.3;
Saturation_I_RP_Min = -0.3;
Saturation_I_Y_Max = 0.2;
Saturation_I_Y_Min = -0.2;
Saturation_I_ah = 3.43;
Saturation_I_az = 5;

% throttle limitation
MAX_MAN_THR = 0.9;
MIN_MAN_THR = 0.05;
% max control angle, default 35 deg
MAX_CONTROL_ANGLE_ROLL = 30;
MAX_CONTROL_ANGLE_PITCH  = 30;
% max control angle rate, rad/s 
MAX_CONTROL_ANGLE_RATE_PITCH = 220;
MAX_CONTROL_ANGLE_RATE_ROLL = 220;
MAX_CONTROL_ANGLE_RATE_YAW = 150;
% max control speed, m/s
MAX_CONTROL_VELOCITY_XY = 5;
MAX_CONTROL_VELOCITY_Z = 3;

% First order time constant
TIME_Constant = 0.12;

%Stablized controller
Kp_Stab_ROll = 5.0;
K_Stab_ROllRate = 10.0;
Kp_Stab_ROllRate = 6.0;
Ki_Stab_ROllRate = 0.1;
Kd_Stab_ROllRate = 0.1;
Kp_Stab_Pitch = 5.0;
K_Stab_PitchRate = 1.0;
Kp_Stab_PitchRate = 6.0;
Ki_Stab_PitchRate = 0.1;
Kd_Stab_PitchRate = 0.1;
Kp_Stab_Yaw = 5.0;
K_Stab_YawRate = 1.0;
Kp_Stab_YawRate = 6.0;
Ki_Stab_YawRate = 0.1;
Kd_Stab_YawRate = 0.1;

%Acutator Parameter
spring_stiffness = 10000;
damping_coefficient = 60;

%% run simulink model
% f450_simulation