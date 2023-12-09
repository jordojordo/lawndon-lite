#ifndef MOTOR_H
#define MOTOR_H

#include "controller.h"
#include <Arduino.h>

// Mower Motor pins
#define motorEnaR 5
#define motorEnaL 6
#define motorVcc 7
#define motorPwmR 22
#define motorPwmL 23 

class Motor {
public:
  Motor();

  virtual void setup();
  virtual void loop();
};

extern Motor motor;

#endif // MOTOR_H