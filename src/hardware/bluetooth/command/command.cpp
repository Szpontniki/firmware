#include "./command.h"

Command::Command(std::string name, const std::function<void(Context)> run) : name(name), run(run) {}

std::string Command::getName() {
	return this->name;
}

void Command::handle(Context ctx) {
	return this->run(ctx);
}
