#include "crow/json.h"
#include "../../route.h"

Route currentStateRoute() {
	return Route(HTTPMethod::GET, "/display/current-state", [](Context ctx) {
		auto &json = ctx.response<crow::json::wvalue>();
		auto &pixels = ctx.display.getPixels();

		auto responsePixels = crow::json::wvalue::list();
		for (auto &row : pixels) {
			for (auto &column : row) {
				responsePixels.push_back({
					crow::json::wvalue{
						{"x", column->getX()},
						{"y", column->getY()},
						{"color", crow::json::wvalue::list{
							column->getColor().red,
							column->getColor().green,
							column->getColor().blue,
						}},
					}
				});
			}
		}

		json = std::move(responsePixels);

		return 200;
	});
}
