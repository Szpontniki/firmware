#include "../api.h"
#include "../../display/tui/tui_display.h"

class MockAPI : public API<TUIPixel> {
	public:
		using API::API;
		void start() override;
};
