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
		void render();
	public:
		TUIDisplay(int width, int height);
		~TUIDisplay();
		void colorPixel(int x, int y, Color color);
};
