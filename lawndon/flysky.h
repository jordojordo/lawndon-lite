#ifndef FLYSKY_H
#define FLYSKY_H

#include <Arduino.h>
#include <IBusBM.h>

class Flysky {
public:
  // remote channels
  int flyCH1_roll = 0; // roll | L -> R
  int flyCH2_pitch = 0; // pitch | Up -> Down
  int flyCH3_throttle = 0; // throttle | Up -> Down
  int flyCH4_yaw = 0; // yaw | L -> R

  int flyCH6_swa = 0;
  int flyCH7_swb = 0;
  int flyCH8_swc = 0;
  int flyCH9_swd = 0;

  // motor speeds
  int driveLeftSpeed = 0;
  int driveRightSpeed = 0;

  // motor direction -- 0 = reverse, 1 = forward
  int driveLeftDir = 1;
  int driveRightDir = 1;

  Flysky();

  virtual void setup();

  virtual void loop();

  virtual int readChannel(byte channelInput, int minLimit, int maxLimit,
                          int defaultValue);
};

extern IBusBM ibus;
extern Flysky flysky;

#endif
