#include "../route.h"

Route testRoute = Route(HTTPMethod::GET, "/test_route", [](Context ctx) {
	ctx.display.colorPixel(0, 0, { 0, 0, 0 });

	return 200;
});
