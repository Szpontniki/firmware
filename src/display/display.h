#pragma once

#include "./pixel/pixel.h"

template <typename PixelType>
class Display {
	protected:
		PixelMatrix<PixelType> pixels;
	public:
		void colorPixel(int x, int y, Color color);
};
