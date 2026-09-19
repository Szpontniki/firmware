#include <cstdint>
#include "crow/json.h"
#include "../../route.h"

Route colorPixelsRoute() {
	return Route(HTTPMethod::POST, "/display/color-pixels", [](Context ctx) {
		auto json = crow::json::load(ctx.requestBody);
	
		if (!json) { return 400; }
	
		auto pixels = json["pixels"];
	
		for (const auto& pixel : pixels) {
			int x = pixel["x"].i();
			int y = pixel["y"].i();
	
			auto color = pixel["color"];
	
			uint8_t r = static_cast<uint8_t>(color[0].i());
			uint8_t g = static_cast<uint8_t>(color[1].i());
			uint8_t b = static_cast<uint8_t>(color[2].i());
	
			ctx.display.colorPixel(x, y, { r, g, b });
		}

		return 200;
	});
}
