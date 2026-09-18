#include "./display/tui/tui_display.h"
#include <chrono>
#include <thread>

int main() {
	TUIDisplay display = TUIDisplay(32, 32, true);
	display.render();

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	return 0;
}
