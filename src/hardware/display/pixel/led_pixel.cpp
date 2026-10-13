#include "./led_pixel.h"

LEDPixel::LEDPixel(int x, int y, Color initialColor) {
	this->x = x;
	this->y = y;
	this->setColor(initialColor);
}

// Our boards are wired in a snake pattern when it comes to data flow.
// ------->|
//         V
// <--------
int LEDPixel::getAbsoluteLocation(int displayWidth) {
	if (y % 2 == 0) {
		// Even rows go left to right.
		return y * displayWidth + x;
	} else {
		// Odd rows go right to left.
		return y * displayWidth + (displayWidth - 1 - x);
	}
}
