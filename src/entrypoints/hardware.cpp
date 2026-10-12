#include <Arduino.h>
#include "../hardware/utils/led_globals.h"
#include "../hardware/animations/startup.h"

void setup() {
	setupLEDs();

	LEDDisplay display = LEDDisplay(2, 2);

	LEDStartupAnimation(display);
}

void loop() {
	delay(10);
}
