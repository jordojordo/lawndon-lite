#include "drive.h"
#include <Arduino.h>

void Drive::setDirection(int directionPin, char state) {
  digitalWrite(directionPin, state);
};

void Drive::setBrake(int brakePin, char state) {
  digitalWrite(brakePin, state);
};

void Drive::setWorkDuty(int pwmPin, int value) {
  analogWrite(pwmPin, value); 
}

void Drive::setup() {
  pinMode(leftDirPin, OUTPUT);
  pinMode(leftPwmPin, OUTPUT);
  pinMode(leftBrakePin, OUTPUT);

  pinMode(rightDirPin, OUTPUT);
  pinMode(rightPwmPin, OUTPUT);
  pinMode(rightBrakePin, OUTPUT);
}
