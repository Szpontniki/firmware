#pragma once

#include "Arduino.h"
#include "../display/led_display.h"

struct ProcessCommandContext {
	LEDDisplay &display;
	String command;
};

void startBluetooth(LEDDisplay &display);
