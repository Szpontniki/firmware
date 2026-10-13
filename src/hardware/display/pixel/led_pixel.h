#pragma once

#include "../../../core/display/pixel/pixel.h"

class LEDPixel : public Pixel {
	public:
		LEDPixel(int x, int y, Color initialColor);
		int getAbsoluteLocation(int displayWidth);
};
