#include <memory>
#include "../utils/led_globals.h"
#include "./led_display.h"
#include "./pixel/led_pixel.h"

LEDDisplay::LEDDisplay(int width, int height) {
	// Generate the pixels.
	for (int x = 0; x < width; x++) {
		std::vector<std::unique_ptr<Pixel>> currentRow;

		for (int y = 0; y < height; y++) {
			currentRow.push_back(std::make_unique<LEDPixel>(x, y, Color{ 0, 0, 0 }));
		}

		this->pixels.push_back(std::move(currentRow));
	}

	this->render();
}

// This method accepts a `Pixel` type and later generates
// a `LEDPixel` object from it due to accessibility reasons.
void LEDDisplay::renderPixel(Pixel pixel) {
	LEDPixel led_pixel = LEDPixel{pixel.getX(), pixel.getY(), pixel.getColor()};

	DisplaySize size = getSize();
	auto [width, _] = size;
	int location = led_pixel.getAbsoluteLocation(width);
	auto [r, g, b] = pixel.getColor();
	
	PIXELS.setPixelColor(location, r, g, b);
	PIXELS.show();
}

DisplaySize LEDDisplay::getSize() {
	int height = pixels.size();
	int width = pixels[0].size();

	return DisplaySize{width, height};
}

void LEDDisplay::render() {
	DisplaySize size = getSize();
	auto [width, height] = size;

	for (int x = 0; x < height; x++) {
		std::vector<std::unique_ptr<Pixel>> &currentRow = pixels[x];

		for (int y = 0; y < width; y++) {
			this->renderPixel(*currentRow[y]);
		}
	}
}

void LEDDisplay::colorPixel(int x, int y, Color color) {
	Display::colorPixel(x, y, color);
	this->renderPixel(LEDPixel{x, y, color});
}
