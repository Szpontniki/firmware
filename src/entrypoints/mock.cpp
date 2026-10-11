#include "../mock/display/tui_display.h"
#include "../mock/api/mock_api.h"

int main() {
	TUIDisplay display = TUIDisplay(32, 32);
	MockAPI api = MockAPI(&display);
	api.start();

	return 0;
}
