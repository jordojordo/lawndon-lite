#include "motor.h"
#include "controller.h"
#include <Arduino.h>
#include <IBusBM.h>

Motor motor;

Motor::Motor() {}

void Motor::setup() {
  pinMode(motorEna, OUTPUT);
  pinMode(motorIn1, INPUT);
  pinMode(motorIn2, INPUT);

  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, HIGH);
}

void Motor::loop() {  
  int swdOut = map(controller.control_CH9_swd, 0, 1, 0, 255);

  // Set motor 
  analogWrite(motorEna, swdOut);

  if (controller.control_CH9_swd == 1) {
    analogWrite(motorIn1, HIGH);
  } else {
    analogWrite(motorIn1, LOW);
  }
}