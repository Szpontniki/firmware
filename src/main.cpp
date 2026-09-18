#include "./display/tui/tui_display.h"

int main() {
	TUIDisplay display = TUIDisplay(5, 5);
	display.render();
}
