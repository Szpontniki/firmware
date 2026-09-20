#pragma once

#include "./pixel/pixel.h"

class IDisplay {
	public:
		virtual ~IDisplay() = default;

		virtual void colorPixel(int x, int y, Color color) = 0;
};

template <typename PixelType>
class Display : public IDisplay {
	protected:
		PixelMatrix<PixelType> pixels;
	public:
		void colorPixel(int x, int y, Color color) override;
};
