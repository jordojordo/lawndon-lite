#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

#include "flysky.h"
#include <IBusBM.h>

static IBusBM ibus;

void setup() {
  Serial.begin(115200);

  ibus.begin(Serial);
}

void loop() {
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
