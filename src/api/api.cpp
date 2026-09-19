#include "./api.h"
#include "../display/pixel/tui/tui_pixel.h"

template <typename PixelType>
API<PixelType>::API(Display<PixelType> *display) {
	controlledDisplay = display;
}

template class API<TUIPixel>;
