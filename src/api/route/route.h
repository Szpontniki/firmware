#pragma once

#include "string"
#include "functional"
#include "../../display/display.h"

enum class HTTPMethod {
	GET,
	POST,
	PATCH,
	DELETE,
};

struct Context {
	Display<Pixel> display;
};

class Route {
	private:
		std::string path;
		HTTPMethod method;
		// Returns the HTTP status code.
		const std::function<int(Context)> execute;
	public:
		Route(HTTPMethod method, std::string path, const std::function<int(Context)> execute);
		int run(Context ctx);
};
