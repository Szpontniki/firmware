#include <array>
#include <cstdint>
#include <vector>
#include "ArduinoJson.h"
#include "ArduinoJson/Array/JsonArrayConst.hpp"
#include "../command.h"

struct RequestPixel {
	int x;
	int y;
	std::array<int, 3> color;
};

std::vector<RequestPixel> parseJSONPixels(JsonArrayConst jsonPixels) {
	std::vector<RequestPixel> pixels;
	pixels.reserve(jsonPixels.size());

	for (JsonObjectConst item : jsonPixels) {
		JsonArrayConst color = item["color"].as<JsonArrayConst>();
	
		if (color.size() != 3) {
			Serial.println("Invalid pixel color");
			continue;
		}
	
		RequestPixel pixel;
		pixel.x = item["x"].as<int>();
		pixel.y = item["y"].as<int>();
	
		pixel.color = {
			color[0].as<int>(),
			color[1].as<int>(),
			color[2].as<int>()
		};
	
		pixels.push_back(pixel);
	}

	return pixels;
}

Command colorPixelsCommand() {
	return Command("/display/color-pixels", [](Context ctx) {
		JsonDocument doc;
		DeserializationError error = deserializeJson(doc, ctx.requestBody);

		if (error) {
			Serial.print("JSON parsing failed: ");
			Serial.println(error.c_str());
			return;
		}

		JsonArrayConst jsonPixels = doc["pixels"].as<JsonArrayConst>();
		std::vector<RequestPixel> pixels = parseJSONPixels(jsonPixels);

		for (auto pixel : pixels) {
			uint8_t r = pixel.color[0];
			uint8_t g = pixel.color[1];
			uint8_t b = pixel.color[2];

			ctx.display.colorPixel(pixel.x, pixel.y, { r, g, b });
		}
	});
}
