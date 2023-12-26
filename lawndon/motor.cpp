#include "motor.h"
#include "controller.h"
#include <Arduino.h>
#include <IBusBM.h>

Motor motor;

Motor::Motor() {}

void Motor::setup() {
  Console.println(F("Initializing motor config"));

  setupTimer4();
  pinMode(motorEnaR, OUTPUT);
  pinMode(motorEnaL, OUTPUT);
  pinMode(motorPwmR, OUTPUT);
  pinMode(motorPwmL, OUTPUT);

  digitalWrite(motorEnaR, HIGH);
  digitalWrite(motorEnaL, HIGH);
  analogWrite(motorPwmR, LOW);
  analogWrite(motorPwmL, LOW);

  Console.println(F("Motor setup complete"));
}

void Motor::loop() {  
  int swdOut = map(controller.control_CH9_swd, 0, 1, 0, 255);

  if (controller.control_CH9_swd == 1) {
    analogWrite(motorPwmR, swdOut);
  } else {
    analogWrite(motorPwmR, swdOut);
  }
}

// Adjusts Timer4 for a frequency of 1kHz
// [optional]: depends on the mower motor requirements
void Motor::setupTimer4() {
  TCCR4B = TCCR4B & 0b11111000 | 0x01; // Change prescaler
  ICR4 = 32000; // Adjust the TOP value for 1kHz at 16MHz clock speed
}
