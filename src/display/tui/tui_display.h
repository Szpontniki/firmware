#pragma once

#include "../display.h"
#include "../pixel/tui/tui_pixel.h"

class TUIDisplay : public Display<TUIPixel> {
	public:
		TUIDisplay(int width, int height);
		void render();
};
