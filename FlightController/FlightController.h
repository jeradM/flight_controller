#ifndef __FLIGHT_CONTROLLER_H__
#define __FLIGHT_CONTROLLER_H__

#include "MotorOutput.h"
#include "RadioInput.h"
#include "PID.h"
#include "FC_IMU.h"

#define LED_BLUE            12
#define LED_GREEN           13

#define PID_RATE_ROL        0
  #define PID_RATE_ROL_P   .5
  #define PID_RATE_ROL_I   .5
  #define PID_RATE_ROL_D   .5
  #define PID_RATE_ROL_IL  .5
  
#define PID_RATE_PIT        1
  #define PID_RATE_PIT_P    .5
  #define PID_RATE_PIT_I    .5
  #define PID_RATE_PIT_D    .5
  #define PID_RATE_PIT_IL   .5
  
#define PID_RATE_YAW        2
  #define PID_RATE_YAW_P    .5
  #define PID_RATE_YAW_I    .5
  #define PID_RATE_YAW_D    .5
  #define PID_RATE_YAW_IL   .5
  
#define PID_STAB_ROL        3
  #define PID_STAB_ROL_P    .5
  #define PID_STAB_ROL_I    .5
  #define PID_STAB_ROL_D    .5
  #define PID_STAB_ROL_IL   .5
  
#define PID_STAB_PIT        4
  #define PID_STAB_PIT_P    .5
  #define PID_STAB_PIT_I    .5
  #define PID_STAB_PIT_D    .5
  #define PID_STAB_PIT_IL   .5
  
#define PID_STAB_YAW        5
  #define PID_STAB_YAW_P    .5
  #define PID_STAB_YAW_I    .5
  #define PID_STAB_YAW_D    .5
  #define PID_STAB_YAW_IL   .5

class FlightController {
public:
  FlightController() {}
  
  void init();
  void calibrate_radio();
  
  // Update Inputs/Outputs/Auxillary
  // Call in main program loop
  void update();
  
  
private:
  PID _pids[6];
  FC_IMU _imu;
  MotorOutput _motors;
  RadioInput  _radio;
  
  int16_t _accel[3];
  int16_t _gyro[3];
  uint16_t _radio_prev[8];
  uint16_t _motor_prev[4];
  
  bool _initialized;
  bool _auto_level;
  
  // Auxillary Input Functions
  void _parse_aux();
  void _setup_pids();
  void _led_blue(bool on);
  void _led_green(bool on);
  
};


#endif