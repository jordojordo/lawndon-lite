#ifndef MOTOR_H
#define MOTOR_H

#include "controller.h"
#include <Arduino.h>

// Mower Motor pins
#define motorEnaR 22
#define motorEnaL 23
#define motorPwmR 6
#define motorPwmL 7

class Motor {
public:
  Motor();

  virtual void setup();
  virtual void loop();
  virtual void setupTimer4();
};

extern Motor motor;

#endif // MOTOR_H