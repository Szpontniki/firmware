#include <ncurses.h>
#include "./tui_display.h"

TUIDisplay::TUIDisplay(int width, int height) {
	// Generate the pixels.
	for (int x = 0; x < width; x++) {
		std::vector<TUIPixel> currentRow;

		for (int y = 0; y < height; y++) {
			currentRow.push_back(TUIPixel({ 255, 255, 255 }));
		}

		pixels.push_back(currentRow);
	}

	// Setup TUI thread.
	running = true;
	needsRedraw = true;
	thread = std::thread(&TUIDisplay::setup, this);
}

void TUIDisplay::draw() {
	mvprintw(0, 0, "Hello, World!");
}

void TUIDisplay::render() {
	{
		std::lock_guard lock(busyMutex);
		needsRedraw = true;
	}

	cv.notify_one();
}

void TUIDisplay::setup() {
	initscr();
	curs_set(0);

	while (true) {
		std::unique_lock lock(busyMutex);

		cv.wait(lock, [this] {
			return needsRedraw || !running;
		});

		if (!running) break;

		needsRedraw = false;
		lock.unlock();

		draw();

		refresh();
	}

	endwin();
}

TUIDisplay::~TUIDisplay() {
	{
		std::lock_guard lock(busyMutex);
		running = false;
	}

	cv.notify_one();

	if (thread.joinable()) thread.join();
}
