// Copyright 2022-2023 The MathWorks, Inc.
// Generated 09-Sep-2026 23:45:07
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "softdrone_pid_types.h"
// Generic pub-sub header
#include "slros2_generic_pubsub.h"
// Generic service header
#include "slros2_generic_service.h"
extern rclcpp::Node::SharedPtr SLROSNodePtr;
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, hist, dep, dur, rel)  \
    {                                                   \
        qosStruct.history = hist;                       \
        qosStruct.depth = dep;                          \
        qosStruct.durability = dur;                     \
        qosStruct.reliability = rel;                    \
    }
#endif
inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
    rclcpp::QoS qos(rclcpp::QoSInitialization::from_rmw(qosProfile));
    if (RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL == qosProfile.durability) {
        qos.transient_local();
    } else {
        qos.durability_volatile();
    }
    if (RMW_QOS_POLICY_RELIABILITY_RELIABLE == qosProfile.reliability) {
        qos.reliable();
    } else {
        qos.best_effort();
    }
    return qos;
}
// softdrone_pid/Control System/AttitudeControl/Publish
extern SimulinkPublisher<geometry_msgs::msg::Vector3,SL_Bus_geometry_msgs_Vector3> Pub_softdrone_pid_658;
// softdrone_pid/Publish
extern SimulinkPublisher<custom_msgs::msg::WriteOnBoardPWM,SL_Bus_custom_msgs_WriteOnBoardPWM> Pub_softdrone_pid_451;
// softdrone_pid/Publish1
extern SimulinkPublisher<geometry_msgs::msg::Vector3,SL_Bus_geometry_msgs_Vector3> Pub_softdrone_pid_597;
// softdrone_pid/Publish2
extern SimulinkPublisher<geometry_msgs::msg::Vector3,SL_Bus_geometry_msgs_Vector3> Pub_softdrone_pid_609;
// softdrone_pid/Control System/AttitudeControl/Subscribe
extern SimulinkSubscriber<geometry_msgs::msg::Vector3,SL_Bus_geometry_msgs_Vector3> Sub_softdrone_pid_627;
// softdrone_pid/Subscribe
extern SimulinkSubscriber<custom_msgs::msg::ReadSBUSRC,SL_Bus_custom_msgs_ReadSBUSRC> Sub_softdrone_pid_430;
// softdrone_pid/Subscribe1
extern SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_softdrone_pid_434;
#endif
