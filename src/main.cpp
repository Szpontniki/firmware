#include "./display/tui/tui_display.h"
#include <chrono>
#include <thread>

int main() {
	TUIDisplay display = TUIDisplay(32, 32);

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	display.colorPixel(16, 16, { 0, 255, 0 });

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	return 0;
}
