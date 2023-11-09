#ifndef MOTOR_H
#define MOTOR_H

#include "flysky.h"
#include <Arduino.h>

// pins
#define motorEna 5
#define motorIn1 22
#define motorIn2 23 

class Motor : public Flysky {
public:
  Motor();

  virtual void setup();
  virtual void loop();
};

extern Motor motor;

#endif