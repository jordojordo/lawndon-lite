#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include <IBusBM.h>

// baudrates
#define CONSOLE_BAUDRATE        19200
#define CONTROLLER_BAUDRATE     115200

// serial ports
#define Console                 Serial
#define ControllerPort          Serial1

class Controller {
public:
  // Right joystick
  int control_CH1_roll = 0; // roll | L -> R
  int control_CH2_pitch = 0; // pitch | Up -> Down

  // Unused
  // int control_CH3_throttle = 0; // throttle | Up -> Down
  // int control_CH4_yaw = 0; // yaw | L -> R
  // int control_CH6_swa = 0;
  // int control_CH7_swb = 0;
  // int control_CH8_swc = 0;

  // Motor mower switch
  int control_CH9_swd = 0;

  Controller();

  virtual void setup();
  virtual void loop();

  virtual int readChannel(byte channelInput, int minLimit, int maxLimit,
                          int defaultValue);
};

extern IBusBM ibus;
extern Controller controller;

#endif // CONTROLLER_H
