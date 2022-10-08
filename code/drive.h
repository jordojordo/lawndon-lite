#ifndef DRIVE_H
#define DRIVE_H
#include "flysky.h"
#include <Arduino.h>

// pin defs
#define pinDriveLeftDir 12
#define pinDriveLeftPwm 3
#define pinDriveLeftBrake 9

#define pinDriveRightDir 13
#define pinDriveRightPwm 11
#define pinDriveRightBrake 8

// baudrates
#define CONSOLE_BAUDRATE 19200
#define FLYSKY_BAUDRATE 115200

// serial ports
#define Console Serial
#define Flyskyport Serial1

class Drive : public Flysky {
public:
  Drive();

  virtual void setup(void);

  virtual void controlDriveLeftMotor(int speed, int direction);
  virtual void controlDriveRightMotor(int speed, int direction);
};

extern Drive drive;

#endif