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
	public:
		void setColor(Color color);
		Color getColor();
};

using PixelMatrix = std::vector<std::vector<std::unique_ptr<Pixel>>>;
