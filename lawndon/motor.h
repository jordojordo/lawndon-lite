#ifndef MOTOR_H
#define MOTOR_H

#include "controller.h"
#include <Arduino.h>

// Mower Motor pins
#define motorEna 5
#define motorIn1 22
#define motorIn2 23 

class Motor {
public:
  Motor();

  virtual void setup();
  virtual void loop();
};

extern Motor motor;

#endif // MOTOR_H