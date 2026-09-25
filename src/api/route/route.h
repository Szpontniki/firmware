#pragma once

#include <variant>
#include <any>
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
	std::string requestBody;
	// This depends on implementation. We can't type it here.
	std::any &responseObject;

	template<typename T>
	T& response()
	{
		if (!responseObject.has_value()) {
			responseObject = T{};
		}

		return std::any_cast<T&>(responseObject);
	}
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
