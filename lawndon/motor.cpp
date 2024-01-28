#include "motor.h"
#include "controller.h"
#include <Arduino.h>
#include <IBusBM.h>
#include <Servo.h>

Motor motor;
Servo mowerEsc;

Motor::Motor() {}

void Motor::setup() {
  Console.println(F("Initializing motor config"));

  // Attach Mower ESC
  Console.println(F("Attaching mower ESC"));
  mowerEsc.attach(ESC_MOWER_PWM, 1000, 2000);
  delay(1);

  // Arm Mower ESC
  Console.println(F("Arming mower ESC"));
  mowerEsc.writeMicroseconds(1000);

  // Set mower ESC pins
  pinMode(ESC_MOWER_PWM, OUTPUT);
  pinMode(ESC_MOWER_POWER, OUTPUT);

  Console.println(F("Motor setup complete"));
}

void Motor::loop() {  
  if (controller.control_CH9_swd == 1) {
    mowerEsc.writeMicroseconds(2000);
  } else {
    mowerEsc.writeMicroseconds(1000);
  }
}
