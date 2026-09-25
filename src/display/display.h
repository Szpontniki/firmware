#pragma once

#include "./pixel/pixel.h"

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
