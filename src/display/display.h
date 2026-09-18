#pragma once

#include "./pixel/pixel.h"

template <typename PixelType>
class Display {
	protected:
		PixelMatrix<PixelType> pixels;
};
