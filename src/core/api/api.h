#pragma once

#include "../display/display.h"

class API {
	private:
		IDisplay *controlledDisplay;
	public:
		API(IDisplay *display);
		virtual void start() = 0;
};
