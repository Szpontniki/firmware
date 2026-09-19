#include "./mock_api.h"
#include "../route/routes/routes.h"
#include <crow/common.h>

// Other API implementations won't use crow, so we need to have a way
// to convert our internal HTTPMethod into crow's one. I know that this
// looks disgustingly, but it's a necessity. I think that the only way to
// actually do this programmatically would be with some crazy macros, but
// being honest even this seems more elegant at that point.
crow::HTTPMethod matchHTTPMethodToCrowMethod(HTTPMethod method) {
	switch (method) {
		case HTTPMethod::GET:
			return crow::HTTPMethod::GET;
		case HTTPMethod::POST:
			return crow::HTTPMethod::POST;
		case HTTPMethod::PATCH:
			return crow::HTTPMethod::PATCH;
		case HTTPMethod::DELETE:
			return crow::HTTPMethod::DELETE;
	}

	return crow::HTTPMethod::GET;
}

MockAPI::MockAPI(IDisplay *display) : API(display) {
	for (int i = 0; i < routes.size(); i++) {
		Route currentRoute = routes[i];

		app
			.route_dynamic(currentRoute.getPath())
			.methods(matchHTTPMethodToCrowMethod(currentRoute.getMethod()))
				([currentRoute, display](const crow::request& req) {
					Context ctx = Context { *display };

					int status = currentRoute.run(ctx);
					return crow::response(status);
				});
	}
}

void MockAPI::start() {
	app.loglevel(crow::LogLevel::CRITICAL);
	app.port(3000).multithreaded().run();
}
