#include "pixel.h"

void Pixel::setColor(Color color) {
	this->currentColor = color;
}

Color Pixel::getColor() {
	return this->currentColor;
}
