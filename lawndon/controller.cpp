#include "controller.h"
#include <Arduino.h>

IBusBM ibus;
Controller controller;

Controller::Controller() {}

// Reads the supplied channel from Serial1 (ControllerPort) and
// returns either the supplied default value or a mapped value between limits
int Controller::readChannel(byte channelInput, int minLimit, int maxLimit,
                            int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);

  if (ch < 100) {
    return defaultValue;
  }

  return map(ch, 1000, 2000, minLimit, maxLimit);
};

void Controller::setup() {
  Console.println(F("Sending controller config"));
  ControllerPort.begin(CONTROLLER_BAUDRATE);
  ibus.begin(ControllerPort);

  Console.println(F("Controller setup complete"));
}

void Controller::loop() {
  // Right joystick
  control_CH1_roll = readChannel(0, 1000, 2000, 1500);      // roll | L -> R
  control_CH2_pitch = readChannel(1, 1000, 2000, 1500);     // pitch | Up -> Down

  // Unused
  // control_CH3_throttle = readChannel(2, 1000, 2000, 1500);  // throttle | Up -> Down
  // control_CH4_yaw = readChannel(3, 1000, 2000, 1500);       // yaw | L -> R
  // control_CH6_swa = readChannel(6, 0, 1, 0);
  // control_CH7_swb = readChannel(7, 0, 1, 0);
  // control_CH8_swc = readChannel(8, 0, 2, 0);

  // Mower motor switch
  control_CH9_swd = readChannel(9, 0, 1, 0);
}
