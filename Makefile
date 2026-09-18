COMPILER := g++
PRODUCTIONCOMPILERFLAGS := -O3 -Wall -Wextra -Wpedantic -DNDEBUG
SRC := $(shell find . -name '*.cpp')
OUT := ./firmware

all: $(OUT)

$(OUT): $(SRC)
	$(COMPILER) -o $(OUT) $(SRC)

debug:
	$(COMPILER) -g -o $(OUT) $(SRC)

production:
	$(COMPILER) $(PRODUCTIONCOMPILERFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
