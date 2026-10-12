#include "../command.h"
#include "../../../utils/serial_globals.h"

Command colorPixelsCommand() {
	return Command("/display/color-pixels", [](Context ctx) {
		ctx.display.colorPixel(0, 0, { 255, 255, 255 });
	});
}
