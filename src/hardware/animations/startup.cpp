#include "../display/led_display.h"
#include "../utils/led_globals.h"

void LEDStartupAnimation(LEDDisplay &display) {
	DisplaySize size = display.getSize();
	auto [width, height] = size;

	int prevY = -1;
	int prevX = -1;
	
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < height; x++) {
			if (prevY != -1 && prevX != -1) display.colorPixel(prevX, prevY, Color { 0, 0, 0 });
			display.colorPixel(x, y, Color { 255, 255, 255 });

			prevX = x;
			prevY = y;

			delay(ANIMATION_THROTTLE_MS);
		}
	}

	display.colorPixel(prevX, prevY, Color { 0, 0, 0 });
}
