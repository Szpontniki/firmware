#include "./route.h"

Route::Route(HTTPMethod method, std::string path, const std::function<int(Context)> execute)
	: path(path), method(method), execute(execute) {}

int Route::run(Context ctx) {
	return this->execute(ctx);
}
