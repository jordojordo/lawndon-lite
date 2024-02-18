#ifndef MOTOR_H
#define MOTOR_H

#include "controller.h"
#include <Arduino.h>

// Mower Motor pins
#define ESC_MOWER_POWER 6
#define ESC_MOWER_PWM 7

class Motor {
public:
  Motor();

  virtual void setup();
  virtual void loop();

  virtual void setupTimer4();
};

extern Motor motor;

#endif // MOTOR_H