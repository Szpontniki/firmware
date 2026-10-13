#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include "./command/commands/commands.h"
#include "./utils.h"
#include "./service.h"

#define SERVICE_UUID "efc0f31a-7670-4f0c-99de-5b7208a535f5"
#define CHARACTERISTIC_UUID "c5f22057-f1d6-4b79-8473-ef42d759c3cb"

void processCommand(ProcessCommandContext ctx) {
	String command = ctx.command;
	command.trim();

	Serial.print("Received command: ");
	Serial.println(command);

	std::array<String, 2> splitValues = splitCommandString(command);
	String commandName = splitValues[0];
	commandName.toLowerCase();
	String args = splitValues[1];
	bool handled = false;

	for (auto command : commands) {
		if (commandName != command.getName().c_str()) continue;

		command.handle({ ctx.display, std::string(args.c_str()) });
		handled = true;
	}

	if (!handled) Serial.println("Couldn't find the command!");
}

class CommandCallbacks : public BLECharacteristicCallbacks {
	private:
		LEDDisplay &display;

	public:
		explicit CommandCallbacks(LEDDisplay &display)
			: display(display) {}

		void onWrite(BLECharacteristic *characteristic) override {
			String command = characteristic->getValue().c_str();

			if (command.length() == 0)
				return;

			ProcessCommandContext ctx = ProcessCommandContext{this->display, command};
			processCommand(ctx);
		}
};

class ServerCallbacks : public BLEServerCallbacks {
	void onDisconnect(BLEServer *pServer) override {
		Serial.println("Client disconnected. Restarting advertising...");
		BLEDevice::startAdvertising();
	}
};

void startBluetooth(LEDDisplay &display) {
	BLEDevice::init("FlashingLights");

	BLEServer *server = BLEDevice::createServer();
	server->setCallbacks(new ServerCallbacks());

	BLEService *service = server->createService(SERVICE_UUID);

	BLECharacteristic *commandCharacteristic;
	commandCharacteristic = service->createCharacteristic(
		CHARACTERISTIC_UUID,
		BLECharacteristic::PROPERTY_READ |
		BLECharacteristic::PROPERTY_WRITE |
		BLECharacteristic::PROPERTY_WRITE_NR
	);
	commandCharacteristic->setCallbacks(new CommandCallbacks(display));

	service->start();

	BLEAdvertising *advertising = BLEDevice::getAdvertising();
	advertising->addServiceUUID(SERVICE_UUID);
	advertising->setScanResponse(true);
	advertising->setMinPreferred(0x06);
	advertising->setMaxPreferred(0x12);

	BLEDevice::startAdvertising();
}
