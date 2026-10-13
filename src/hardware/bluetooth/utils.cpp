#include "./utils.h"

std::array<String, 2> splitCommandString(String command) {
	bool pastSeparator = false;
	String name = "";
	String args = "";

	for (unsigned int i = 0; i < command.length(); i++) {
		char c = command[i];

		if (c == ';') {
			pastSeparator = true;
			continue;
		}

		if (pastSeparator) {
			args.concat(c);
		}
		else {
			name.concat(c);
		}
	}

	return {name, args};
}
