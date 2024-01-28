#include "drive.h"
#include "controller.h"
#include <Arduino.h>
#include <Servo.h>

Servo leftEsc;
Servo rightEsc;
Drive drive;

Drive::Drive() {};

void Drive::setup() {
  Console.begin(CONSOLE_BAUDRATE);
  Console.println(F("__________SETUP__________"));
  Console.println(F("Initializing drive config"));
  
  // Attach ESCs
  Console.println(F("Attaching ESCs"));
  leftEsc.attach(ESC_LEFT_PWM, 1000, 2000);
  rightEsc.attach(ESC_RIGHT_PWM, 1000, 2000);
  delay(1);

  // Calibrate ESCs ( Needed for initial setup )
  // Console.println(F("Calibrating left ESC"));
  // calibrateEsc(leftEsc);
  // Console.println(F("Calibrating right ESC"));
  // calibrateEsc(rightEsc);

  // Arm ESCs
  Console.println(F("Arming left ESC"));
  armEsc(leftEsc);

  Console.println(F("Arming right ESC"));
  armEsc(rightEsc);
  delay(1);


  // Set ESC pins
  pinMode(ESC_LEFT_PWM, OUTPUT);
  pinMode(ESC_LEFT_POWER, OUTPUT);
  pinMode(ESC_RIGHT_PWM, OUTPUT);
  pinMode(ESC_RIGHT_POWER, OUTPUT);
  
  Console.println(F("Drive setup complete"));
}

void Drive::loop() {
  // Calculate turning speed
  int mappedThrottle = map(controller.control_CH1_roll, ESC_MIN_THROTTLE, ESC_MAX_THROTTLE, -500, 500);

  // Determine direction and adjust motor speeds
  if (controller.control_CH2_pitch >= ESC_IDLE_THROTTLE) {
    // Forward
    driveLeftSpeed = controller.control_CH2_pitch + mappedThrottle;
    driveRightSpeed = controller.control_CH2_pitch - mappedThrottle;
  } else {
    // Reverse
    driveLeftSpeed = controller.control_CH2_pitch - mappedThrottle;
    driveRightSpeed = controller.control_CH2_pitch + mappedThrottle;
  }

  // Constrain speed
  driveLeftSpeed = constrain(driveLeftSpeed, ESC_MIN_THROTTLE, ESC_MAX_THROTTLE);
  driveRightSpeed = constrain(driveRightSpeed, ESC_MIN_THROTTLE, ESC_MAX_THROTTLE);

  // Drive motors
  controlDriveMotor(driveLeftSpeed, leftEsc);
  controlDriveMotor(driveRightSpeed, rightEsc);

  // Used for debugging control
  // Serial.print("Left speed = ");
  // Serial.print(driveLeftSpeed);
  // Serial.print("  |  Right speed = ");
  // Serial.print(driveRightSpeed);
  // Serial.print("  |  Roll = ");
  // Serial.print(controller.control_CH1_roll);
  // Serial.print("  |  Pitch = ");
  // Serial.print(controller.control_CH2_pitch);
  // Serial.println();

  delay(50);
}

// Initialize ESC as bi-directional
void Drive::calibrateEsc(Servo esc) {
  esc.writeMicroseconds(ESC_ARM_TIME);
  delay(ESC_ARM_TIME);
  esc.writeMicroseconds(ESC_MIN_THROTTLE);
  delay(ESC_ARM_TIME);
  esc.writeMicroseconds(ESC_IDLE_THROTTLE);
  delay(ESC_ARM_TIME);
}

// Initialize ESC
void Drive::armEsc(Servo esc) {
  esc.writeMicroseconds(ESC_ARM_SIGNAL);
}

// Controls supplied ESC by writing speed in microseconds
void Drive::controlDriveMotor(int speed, Servo esc) {
  if (isDeadzone(speed)) {
    speed = ESC_IDLE_THROTTLE;
  }

  int curSpeed = esc.readMicroseconds();

  // The controller flutters signal occasionally +-10, so we do not write those flutters to the motor
  if (curSpeed < (speed - ESC_FLUTTER_RANGE) || curSpeed > (speed + ESC_FLUTTER_RANGE)) {
    esc.writeMicroseconds(speed);
  }
}

// Determines if speed falls between 1400 - 1600
// Ensures motors will not turn until joystick is pressed
bool Drive::isDeadzone(int speed) {
  return (speed >= (ESC_IDLE_THROTTLE - ESC_DEADZONE_RANGE) && speed <= (ESC_IDLE_THROTTLE + ESC_DEADZONE_RANGE));
}
