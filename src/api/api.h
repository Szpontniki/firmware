#include "../display/display.h"

template<typename PixelType>
class API {
	private:
		Display<PixelType> *controlledDisplay;
	public:
		API(Display<PixelType> *display);
		virtual void start() = 0;
};
