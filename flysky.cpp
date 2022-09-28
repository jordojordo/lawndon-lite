#include "flysky.h"
#include "drive.h"
#include <Arduino.h>
#include <stdlib.h>

Drive drive;
IBusBM ibus;
Flysky flysky;

Flysky::Flysky() {}

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value
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
  flyCH1 = readChannel(0, -100, 100, 0); // yaw | L -> R
  flyCH2 = readChannel(1, -100, 100, 0); // yaw | Up -> Down
  flyCH3 = readChannel(2, 0, 155, 0);    // throttle | Up -> Down
  flyCH4 = readChannel(3, -100, 100, 0); // throttle | L -> R

  Serial.print("  |  Ch1 = ");
  Serial.print(flyCH1);
  Serial.print(" | Ch2 = ");
  Serial.print(flyCH2);
  Serial.print(" | Ch3 = ");
  Serial.print(flyCH3);
  Serial.print(" | Ch4 = ");
  Serial.print(flyCH4);

  Serial.println();

  // set speed
  driveLeftSpeed = flyCH3;
  driveRightSpeed = flyCH3;

  // set direction
  if (flyCH2 >= 0) {
    driveLeftDir = 1;
    driveRightDir = 1;
    Serial.println("-----Forward-----");
  } else {
    driveLeftDir = 0;
    driveRightDir = 0;
    Serial.println("-----Reverse-----");
  }

  // calculate turning speed
  if (flyCH1 != 0 && flyCH2 > 0) {
    driveLeftSpeed += abs(flyCH2 + flyCH1);
    driveRightSpeed += abs(flyCH2 - flyCH1);
  } else {
    driveLeftSpeed += abs(flyCH2);
    driveRightSpeed += abs(flyCH2);
  }

  // constrain speed
  driveLeftSpeed = constrain(driveLeftSpeed, 0, 255);
  driveRightSpeed = constrain(driveRightSpeed, 0, 255);

  // drive motors
  drive.controlDriveLeftMotor(driveLeftSpeed, driveLeftDir);
  drive.controlDriveRightMotor(driveRightSpeed, driveRightDir);

  Serial.print("Left speed = ");
  Serial.print(driveLeftSpeed);
  Serial.print("  |  Right speed = ");
  Serial.print(driveRightSpeed);

  delay(50);
}
