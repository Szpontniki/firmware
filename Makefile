COMPILERFLAGS := $(shell pkg-config --cflags notcurses)
LINKERFLAGS := $(shell pkg-config --libs notcurses)
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
