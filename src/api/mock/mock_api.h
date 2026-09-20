#pragma once

#include <crow/app.h>
#include "../api.h"
#include "../../display/tui/tui_display.h"

class MockAPI : public API {
	private:
		crow::SimpleApp app;
	public:
		MockAPI(IDisplay *display);
		void start() override;
};
