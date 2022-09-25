#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

#include "flysky.h"
#include <IBusBM.h>

static IBusBM ibus;

void setup() {
  // Start serial monitor
  Serial.begin(115200);

  // Attach iBus object to serial port
  ibus.begin(Serial);
}

void loop() {

  // Cycle through first 5 channels and determine values
  // Print values to serial monitor
  // Note IBusBM library labels channels starting with "0"
  for (byte i = 0; i < 5; i++) {
    int value = readChannel(i, -100, 100, 0);
    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(value);
    Serial.print(" | ");
  }

  Serial.println();

  delay(10);
}
