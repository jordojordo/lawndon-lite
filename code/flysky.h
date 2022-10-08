#ifndef FLYSKY_H
#define FLYSKY_H

#include <Arduino.h>
#include <IBusBM.h>

class Flysky {
public:
  // remote channels
  int flyCH1 = 0; // yaw | L -> R
  int flyCH2 = 0; // yaw | Up -> Down
  int flyCH3 = 0; // throttle | Up -> Down
  int flyCH4 = 0; // throttle | L -> R

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
