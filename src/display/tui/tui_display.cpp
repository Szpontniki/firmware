#include <notcurses/notcurses.h>
#include <locale.h>
#include "./tui_display.h"

TUIDisplay::TUIDisplay(int width, int height, bool terminateOnExit) {
	// Generate the pixels.
	for (int x = 0; x < width; x++) {
		std::vector<TUIPixel> currentRow;

		for (int y = 0; y < height; y++) {
			currentRow.push_back(TUIPixel({ 255, 255, 255 }));
		}

		pixels.push_back(currentRow);
	}

	// Setup TUI thread.
	setlocale(LC_ALL, "");

	notcurses_options opts = {};
	opts.flags = NCOPTION_SUPPRESS_BANNERS;

	nc = notcurses_init(&opts, stdout);
	if (!nc) return;

	running = true;
	needsRedraw = true;
	thread = std::thread(&TUIDisplay::setup, this);
	inputThread = std::thread(&TUIDisplay::setupInputHandling, this);
}

void TUIDisplay::draw() {
	ncplane *n = notcurses_stdplane(nc);

	for (int x = 0; x < pixels.size(); x++) {
		std::vector<TUIPixel> currentRow = pixels[x];

		for (int y = 0; y < currentRow.size(); y++) {
			Color currentPixelColor = currentRow[y].getColor();
			uint64_t currentChannels = ncplane_channels(n);

			ncplane_set_fg_rgb8(n, currentPixelColor.red, currentPixelColor.green, currentPixelColor.blue);
			ncplane_set_bg_rgb8(n, currentPixelColor.red, currentPixelColor.green, currentPixelColor.blue);
			ncplane_printf_yx(n, y, x, ".");

			ncplane_set_channels(n, currentChannels);
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
	while (running) {
		std::unique_lock lock(busyMutex);

		cv.wait(lock, [this] {
			return needsRedraw || !running;
		});

		if (!running) break;

		needsRedraw = false;
		lock.unlock();

		draw();

		notcurses_render(nc);
	}

	notcurses_stop(nc);
}

void TUIDisplay::setupInputHandling() {
	uint32_t id;
	ncinput ni;

	while (running) {
		id = notcurses_get_blocking(nc, &ni);

		if (id == 'q' || id == 'Q') {
			{
				std::lock_guard lock(busyMutex);
				running = false;
			}

			cv.notify_one();
			break;
		}
	}
}

TUIDisplay::~TUIDisplay() {
	{
		std::lock_guard lock(busyMutex);
		running = false;
	}

	cv.notify_one();

	if (inputThread.joinable()) inputThread.join();
	if (thread.joinable()) thread.join();
}
