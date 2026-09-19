#pragma once

#include <variant>
#include "string"
#include "functional"
#include "../../display/display.h"
#include "../../display/pixel/tui/tui_pixel.h"

enum class HTTPMethod {
	GET,
	POST,
	PATCH,
	DELETE,
};

struct Context {
	IDisplay &display;
};

class Route {
	private:
		std::string path;
		HTTPMethod method;
		// Returns the HTTP status code.
		const std::function<int(Context)> execute;
	public:
		Route(HTTPMethod method, std::string path, const std::function<int(Context)> execute);
		int run(Context ctx) const;

		std::string getPath();
		HTTPMethod getMethod();
};
