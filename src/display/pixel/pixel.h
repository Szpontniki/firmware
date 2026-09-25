#pragma once

#include <memory>
#include <vector>
#include <cstdint>

struct Color {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

class Pixel {
	private:
		Color currentColor;
	protected:
		int x, y;
	public:
		void setColor(Color color);
		Color getColor();
		int getX();
		int getY();
};

using PixelMatrix = std::vector<std::vector<std::unique_ptr<Pixel>>>;
