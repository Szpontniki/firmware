#include <Adafruit_NeoPixel.h>
#include "./led_globals.h"

Adafruit_NeoPixel PIXELS(
	LED_COUNT,
	LED_PIN,
	NEO_GRB + NEO_KHZ800
);

void setupLEDs() {
	PIXELS.begin();
}
