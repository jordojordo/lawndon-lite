#include "motor.h"
#include "controller.h"
#include <Arduino.h>
#include <IBusBM.h>

Motor motor;

Motor::Motor() {}

void Motor::setup() {
  pinMode(motorEnaR, OUTPUT);
  pinMode(motorEnaL, OUTPUT);
  pinMode(motorPwmR, OUTPUT);
  pinMode(motorPwmL, OUTPUT);

  digitalWrite(motorPwmR, LOW);
  digitalWrite(motorPwmL, HIGH);
}

void Motor::loop() {  
  int swdOut = map(controller.control_CH9_swd, 0, 1, 0, 255);

  // Set motor 
  analogWrite(motorEnaR, swdOut);

  if (controller.control_CH9_swd == 1) {
    analogWrite(motorPwmR, HIGH);
  } else {
    analogWrite(motorPwmR, LOW);
  }
}