#include "../../core/display/display.h"
#include "./pixel/led_pixel.h"

struct DisplaySize {
	int width;
	int height;
};

class LEDDisplay : public Display<LEDPixel> {
	private:
		void render();
		void renderPixel(Pixel pixel);
	public:
		DisplaySize getSize();
		LEDDisplay(int width, int height);
		void colorPixel(int x, int y, Color color);
};
