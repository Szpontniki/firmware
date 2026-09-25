#include <stdio.h>
#include <stdlib.h>
#include "./display.h"
#include "./pixel/tui/tui_pixel.h"

template <typename PixelType>
void Display<PixelType>::colorPixel(int x, int y, Color color) {
	if (x > pixels.size() - 1 || y > pixels[0].size() - 1) {
		fprintf(stderr, "Tried to color a pixel out of display's bounds!");
		exit(EXIT_FAILURE);
	}

	pixels[x][y]->setColor(color);
}

template <typename PixelType>
const PixelMatrix& Display<PixelType>::getPixels() const {
	return pixels;
}

template class Display<TUIPixel>;
