#include <vector>
#include "../../../core/api/route/route.h"

extern Route colorPixelsRoute();
extern Route currentStateRoute();

std::vector<Route> routes = {
	colorPixelsRoute(),
	currentStateRoute(),
};
