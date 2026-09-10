#ifndef SOFTDRONE_PID__VISIBILITY_CONTROL_H_
#define SOFTDRONE_PID__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SOFTDRONE_PID_EXPORT __attribute__ ((dllexport))
    #define SOFTDRONE_PID_IMPORT __attribute__ ((dllimport))
  #else
    #define SOFTDRONE_PID_EXPORT __declspec(dllexport)
    #define SOFTDRONE_PID_IMPORT __declspec(dllimport)
  #endif
  #ifdef SOFTDRONE_PID_BUILDING_LIBRARY
    #define SOFTDRONE_PID_PUBLIC SOFTDRONE_PID_EXPORT
  #else
    #define SOFTDRONE_PID_PUBLIC SOFTDRONE_PID_IMPORT
  #endif
  #define SOFTDRONE_PID_PUBLIC_TYPE SOFTDRONE_PID_PUBLIC
  #define SOFTDRONE_PID_LOCAL
#else
  #define SOFTDRONE_PID_EXPORT __attribute__ ((visibility("default")))
  #define SOFTDRONE_PID_IMPORT
  #if __GNUC__ >= 4
    #define SOFTDRONE_PID_PUBLIC __attribute__ ((visibility("default")))
    #define SOFTDRONE_PID_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SOFTDRONE_PID_PUBLIC
    #define SOFTDRONE_PID_LOCAL
  #endif
  #define SOFTDRONE_PID_PUBLIC_TYPE
#endif
#endif  // SOFTDRONE_PID__VISIBILITY_CONTROL_H_
// Generated 09-Sep-2026 23:45:11
 