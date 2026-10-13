#pragma once

// TODO: move this to `core` once `mock` starts supporting bluetooth???
#include <string>
#include "functional"
#include "../../display/led_display.h"

struct Context {
	LEDDisplay &display;
	std::string requestBody;
};

class Command {
	private:
		std::string name;
		const std::function<void(Context)> run;
	public:
		Command(std::string name, const std::function<void(Context)> run);
		std::string getName();
		void handle(Context ctx);
};
