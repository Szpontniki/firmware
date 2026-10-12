#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 2
// TODO: this should probably be configurable later?
#define LED_COUNT 4
#define ANIMATION_DURATION_MS 2000
#define ANIMATION_THROTTLE_MS (ANIMATION_DURATION_MS / LED_COUNT)

Adafruit_NeoPixel pixels(
	LED_COUNT,
	LED_PIN,
	NEO_GRB + NEO_KHZ800
);

void LEDStartupAnimation() {
	for (int i = 0; i < LED_COUNT; i++) {
		int prev = i - 1;

		if (prev >= 0) pixels.setPixelColor(prev, pixels.Color(0, 0, 0));
		pixels.setPixelColor(i, pixels.Color(255, 255, 255));
		pixels.show();

		delay(ANIMATION_THROTTLE_MS);
	}

	pixels.setPixelColor(LED_COUNT - 1, pixels.Color(0, 0, 0));
	pixels.show();
}

void setup() {
	Serial.begin(115200);
	pixels.begin();

	LEDStartupAnimation();
}

void loop() {
	delay(10);
}
