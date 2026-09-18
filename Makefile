COMPILERFLAGS := $(shell pkg-config --cflags ncurses)
LINKERFLAGS := $(shell pkg-config --libs ncurses)
COMPILER := g++
PRODUCTIONCOMPILERFLAGS := -O3 -Wall -Wextra -Wpedantic -DNDEBUG $(COMPILERFLAGS)
SRC := $(shell find . -name '*.cpp')
OUT := ./firmware

all: $(OUT)

$(OUT): $(SRC)
	$(COMPILER) $(COMPILERFLAGS) -o $(OUT) $(SRC) $(LINKERFLAGS)

debug:
	$(COMPILER) $(COMPILERFLAGS) -g -o $(OUT) $(SRC) $(LINKERFLAGS)

production:
	$(COMPILER) $(COMPILERFLAGS) $(PRODUCTIONCOMPILERFLAGS) -o $(OUT) $(SRC) $(LINKERFLAGS)

clean:
	rm -f $(OUT)
