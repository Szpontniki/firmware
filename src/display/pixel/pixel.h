#pragma once

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
	public:
		void setColor(Color color);
		Color getColor();
};

template <typename T>
using PixelMatrix = std::vector<std::vector<T>>;
