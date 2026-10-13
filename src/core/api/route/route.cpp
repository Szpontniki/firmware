#include "./route.h"

Route::Route(HTTPMethod method, std::string path, const std::function<int(Context)> execute)
	: path(path), method(method), execute(execute) {}

int Route::run(Context ctx) const {
	return this->execute(ctx);
}

std::string Route::getPath() {
	return path;
}

HTTPMethod Route::getMethod() {
	return method;
}
