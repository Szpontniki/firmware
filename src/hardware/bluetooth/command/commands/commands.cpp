#include <vector>
#include "../command.h"

extern Command colorPixelsCommand();

std::vector<Command> commands = {
	colorPixelsCommand(),
};
