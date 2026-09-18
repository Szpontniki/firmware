#include "./tui_display.h"

TUIDisplay::TUIDisplay(int width, int height) {
	for (int x = 0; x < width; x++) {
		std::vector<TUIPixel> currentRow;

		for (int y = 0; y < height; y++) {
			currentRow.push_back(TUIPixel({ 255, 255, 255 }));
		}

		pixels.push_back(currentRow);
	}
}

void TUIDisplay::render() {
	// TODO: implement with ncurses.
}
