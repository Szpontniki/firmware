#include "./display/tui/tui_display.h"
#include "./api/mock/mock_api.h"

int main() {
	TUIDisplay display = TUIDisplay(32, 32);
	MockAPI api = MockAPI(&display);
	api.start();

	return 0;
}
