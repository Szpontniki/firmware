#pragma once

#include "./pixel/pixel.h"
#include <stdio.h>
#include <stdlib.h>

class IDisplay {
	public:
		virtual ~IDisplay() = default;

		virtual void colorPixel(int x, int y, Color color) = 0;
		virtual const PixelMatrix& getPixels() const = 0;
};

template <typename PixelType>
class Display : public IDisplay {
	protected:
		PixelMatrix pixels;
	public:
		void colorPixel(int x, int y, Color color) override;
		const PixelMatrix& getPixels() const override;
};

// Normally I'd include below definitions in a separate file but we need
// them here due to how the C++ compiler hadndles template generation.
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
