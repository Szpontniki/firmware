#pragma once

#include <mutex>
#include <notcurses/notcurses.h>
#include <thread>
#include <condition_variable>
#include "../display.h"
#include "../pixel/tui/tui_pixel.h"

class TUIDisplay : public Display<TUIPixel> {
	private:
		std::thread thread;
		std::thread inputThread;

		std::mutex busyMutex;
		std::condition_variable cv;

		bool running;
		bool needsRedraw;

		notcurses *nc;

		void setup();
		void setupInputHandling();
		void draw();
	public:
		TUIDisplay(int width, int height, bool terminateOnExit);
		~TUIDisplay();

		void render();
};
