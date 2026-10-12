#include <Arduino.h>
#include "../hardware/utils/led_globals.h"
#include "../hardware/animations/startup.h"

void setup() {
	setupLEDs();

	LEDDisplay display = LEDDisplay(2, 2);

	LEDStartupAnimation(display);

	display.colorPixel(0, 0, { 0, 0, 255 });
	display.colorPixel(1, 1, { 255, 0, 0 });
}

void loop() {
	delay(10);
}
