#include "drive.h"
#include "flysky.h"
#include <Arduino.h>
#include <Servo.h>

Servo leftEsc;
Servo rightEsc;

Drive::Drive() {};

void Drive::setup() {
  Serial.begin(CONSOLE_BAUDRATE);
  Serial.println(F("SETUP"));

  leftEsc.attach(pinDriveLeftPwm, 1000, 2000);
  rightEsc.attach(pinDriveRightPwm, 1000, 2000);
  delay(1);

  // Arm escs
  leftEsc.write(40);
  rightEsc.write(40);

  pinMode(pinDriveLeftDir, OUTPUT);
  pinMode(pinDriveLeftPwm, OUTPUT);
  pinMode(pinDriveLeftBrake, OUTPUT);
  pinMode(pinDriveLeftPower, OUTPUT);

  pinMode(pinDriveRightDir, OUTPUT);
  pinMode(pinDriveRightPwm, OUTPUT);
  pinMode(pinDriveRightBrake, OUTPUT);
  pinMode(pinDriveRightPower, OUTPUT);

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
  leftEsc.writeMicroseconds(speed);
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
  rightEsc.writeMicroseconds(speed);
}
