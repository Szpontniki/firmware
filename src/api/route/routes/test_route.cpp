#include "../route.h"

Route testRoute = Route(HTTPMethod::GET, "/test_route", [](Context ctx) {
	return 200;
});
