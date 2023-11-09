#include "flysky.h"
#include "drive.h"
#include <Arduino.h>
#include <stdlib.h>

Drive drive;
IBusBM ibus;
Flysky flysky;

Flysky::Flysky() {}

int Flysky::readChannel(byte channelInput, int minLimit, int maxLimit,
                        int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);

  if (ch < 100) {
    return defaultValue;
  }

  return map(ch, 1000, 2000, minLimit, maxLimit);
};

void Flysky::setup() {}

void Flysky::loop() {
  flyCH1_roll = readChannel(0, -1000, 1000, 0); // roll | L -> R
  flyCH2_pitch = readChannel(1, -1000, 1000, 0); // pitch | Up -> Down
  flyCH3_throttle = readChannel(2, 0, 1000, 0);    // throttle | Up -> Down
  flyCH4_yaw = readChannel(3, -1000, 1000, 0); // yaw | L -> R

  // flyCH6_swa = readChannel(6, 0, 1, 0);
  // flyCH7_swb = readChannel(7, 0, 1, 0);
  // flyCH8_swc = readChannel(8, 0, 2, 0);
  // flyCH9_swd = readChannel(9, 0, 1, 0);

  // Serial.print("  |  Roll = ");
  // Serial.print(flyCH1_roll);
  // Serial.print(" | Pitch = ");
  // Serial.print(flyCH2_pitch);
  // Serial.print(" | Throttle = ");
  // Serial.print(flyCH3_throttle);
  // Serial.print(" | Yaw = ");
  // Serial.print(flyCH4_yaw);

  // Serial.println();

  // set speed
  driveLeftSpeed = flyCH3_throttle;
  driveRightSpeed = flyCH3_throttle;

  // set direction
  if (flyCH2_pitch >= 0) {
    driveLeftDir = 1;
    driveRightDir = 1;
    // Serial.println("-----Forward-----");
  } else {
    driveLeftDir = 0;
    driveRightDir = 0;
    // Serial.println("-----Reverse-----");
  }

  // calculate turning speed
  if (flyCH1_roll != 0 && flyCH2_pitch > 0) {
    // forward
    driveLeftSpeed += abs(flyCH2_pitch + flyCH1_roll);
    driveRightSpeed += abs(flyCH2_pitch - flyCH1_roll);
  } else {
    driveLeftSpeed += abs(flyCH2_pitch);
    driveRightSpeed += abs(flyCH2_pitch);
  }

  // constrain speed
  driveLeftSpeed = constrain(driveLeftSpeed, 1000, 2000);
  driveRightSpeed = constrain(driveRightSpeed, 1000, 2000);

  // drive motors
  drive.controlDriveLeftMotor(driveLeftSpeed, driveLeftDir);
  drive.controlDriveRightMotor(driveRightSpeed, driveRightDir);

  // Serial.print("Left speed = ");
  // Serial.print(driveLeftSpeed);
  // Serial.print("  |  Right speed = ");
  // Serial.print(driveRightSpeed);
  Serial.println();

  delay(50);
}
