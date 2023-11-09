#include "motor.h"
#include "flysky.h"
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
  flyCH9_swd = readChannel(9, 0, 1, 0);
  int swdOut = map(flyCH9_swd, 0, 1, 0, 255);

  analogWrite(motorEna, swdOut);

  if (flyCH9_swd == 1) {
    analogWrite(motorIn1, HIGH);
  } else {
    analogWrite(motorIn1, LOW);
  }

  Serial.print(" | flyCH9_swd: ");
  Serial.print(flyCH9_swd);
}