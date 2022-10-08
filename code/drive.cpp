#include "drive.h"
#include "flysky.h"
#include <Arduino.h>

Drive::Drive(){};

void Drive::setup() {
  Serial.begin(CONSOLE_BAUDRATE);
  Serial.println(F("SETUP"));

  pinMode(pinDriveLeftDir, OUTPUT);
  pinMode(pinDriveLeftPwm, OUTPUT);
  pinMode(pinDriveLeftBrake, OUTPUT);

  pinMode(pinDriveRightDir, OUTPUT);
  pinMode(pinDriveRightPwm, OUTPUT);
  pinMode(pinDriveRightBrake, OUTPUT);

  Flysky::setup();

  Serial.println(F("Sending Flysky Config"));
  Serial1.begin(FLYSKY_BAUDRATE);
  ibus.begin(Serial1);
}

void Drive::controlDriveLeftMotor(int speed, int direction) {
  if (direction == 0) {
    // reverse
    digitalWrite(pinDriveLeftDir, LOW);
    digitalWrite(pinDriveLeftBrake, HIGH);
  } else {
    // forward
    digitalWrite(pinDriveLeftDir, HIGH);
    digitalWrite(pinDriveLeftBrake, LOW);
  }

  // control
  analogWrite(pinDriveLeftPwm, speed);
}

void Drive::controlDriveRightMotor(int speed, int direction) {
  if (direction == 0) {
    // reverse
    digitalWrite(pinDriveRightDir, LOW);
    digitalWrite(pinDriveRightBrake, HIGH);
  } else {
    // forward
    digitalWrite(pinDriveRightDir, HIGH);
    digitalWrite(pinDriveRightBrake, LOW);
  }

  // control
  analogWrite(pinDriveRightPwm, speed);
}
