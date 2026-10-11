#include "pixel.h"

void Pixel::setColor(Color color) {
	this->currentColor = color;
}

Color Pixel::getColor() {
	return this->currentColor;
}

int Pixel::getX() {
	return this->x;
}

int Pixel::getY() {
	return this->y;
}
