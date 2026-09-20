#pragma once

#include <crow/app.h>
#include "../api.h"
#include "../../display/tui/tui_display.h"

struct CORSMiddleware {
	struct context {};

	void before_handle(crow::request&, crow::response&, context&) {}

	void after_handle(crow::request&, crow::response &res, context&) {
		res.set_header("Access-Control-Allow-Origin", "*");
		res.set_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
		res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
	}
};

class MockAPI : public API {
	private:
		crow::App<CORSMiddleware> app;
	public:
		MockAPI(IDisplay *display);
		void start() override;
};
