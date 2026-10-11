# This `Makefile` builds only the *mock* version of our app.
# If you want to actually deploy the code to a microcontroller rely on the `pio` command instead.
# For more information please consult the documentation, starting with `README.md`.

COMPILER := g++
COMPILERFLAGS := $(shell pkg-config --cflags notcurses) -I $(CROW_INCLUDE)
LINKERFLAGS := $(shell pkg-config --libs notcurses)
PRODUCTIONCOMPILERFLAGS := -O3 -Wall -Wextra -Wpedantic -DNDEBUG $(COMPILERFLAGS)

SRC := $(shell find ./src -name '*.cpp' ! -path './src/hardware/**' ! -path './src/entrypoints/hardware.cpp')
OUT := ./firmware

all: $(OUT)

$(OUT): $(SRC)
	$(COMPILER) $(COMPILERFLAGS) -o $(OUT) $(SRC) $(LINKERFLAGS)

debug:
	$(COMPILER) $(COMPILERFLAGS) -g -o $(OUT) $(SRC) $(LINKERFLAGS)

production:
	$(COMPILER) $(PRODUCTIONCOMPILERFLAGS) -o $(OUT) $(SRC) $(LINKERFLAGS)

clean:
	rm -f $(OUT)
