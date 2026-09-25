#include "./tui_pixel.h"

TUIPixel::TUIPixel(int x, int y, Color initialColor) {
	this->x = x;
	this->y = y;
	this->setColor(initialColor);
}
