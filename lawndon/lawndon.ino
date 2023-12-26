#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

#include "config.h"

void setup() {
  drive.setup();
  controller.setup();
  motor.setup();

  Console.println(F("__________BEGIN__________"));
}

void loop() {
  drive.loop();
  controller.loop();
  motor.loop();
}
