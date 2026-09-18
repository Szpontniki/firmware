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
	for (int x = 0; x < pixels.size(); x++) {
		std::vector<TUIPixel> currentRow = pixels[x];

		for (int y = 0; y < currentRow.size(); y++) {
			Color currentPixelColor = currentRow[y].getColor();
			init_color(
				1,
				// Ncurses' colors are specified in range 0-1000, and ours are in 0-255.
				// We need to adjust for that. This mathematical formula manages to do so.
				currentPixelColor.red * 1000 / 255,
				currentPixelColor.green * 1000 / 255,
				currentPixelColor.blue * 1000 / 255
			);
			init_pair(1, 1, 1);

			attron(COLOR_PAIR(1));
			mvprintw(y, x, ".");
			attroff(COLOR_PAIR(1));
		}
	}
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
	start_color();
	use_default_colors();

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
