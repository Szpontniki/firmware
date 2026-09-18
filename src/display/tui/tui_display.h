#pragma once

#include <mutex>
#include <thread>
#include <condition_variable>
#include "../display.h"
#include "../pixel/tui/tui_pixel.h"

class TUIDisplay : public Display<TUIPixel> {
	private:
		std::thread thread;

		std::mutex busyMutex;
		std::condition_variable cv;

		bool running;
		bool needsRedraw;

		void setup();
		void draw();
	public:
		TUIDisplay(int width, int height);
		~TUIDisplay();

		void render();
};
