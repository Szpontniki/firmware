#include "../hardware/utils/led_globals.h"
#include "../hardware/utils/serial_globals.h"
#include "../hardware/animations/startup.h"
#include "../hardware/bluetooth/service.h"

void setup() {
	setupSerial();
	setupLEDs();

	static LEDDisplay display(2, 2);

	LEDStartupAnimation(display);

	startBluetooth(display);
}

void loop() {
	delay(10);
}
