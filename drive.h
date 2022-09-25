#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>

class Drive {
public:
  int leftDirPin = 12;
  int leftPwmPin = 3;
  int leftBrakePin = 9;

  int rightDirPin = 13;
  int rightPwmPin = 11;
  int rightBrakePin = 8;

  Drive();

  virtual void setDirection(int directionPin, char state);
  virtual void setBrake(int brakePin, char state);
  virtual void setWorkDuty(int pwmPin, int value);
  virtual void setup();
};

#endif