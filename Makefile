# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -I./third_party/include

# Linker Flags
LDFLAGS = -L./third_party/lib -lhelium -lwolfssl -loqs

# Source Files
SRCS = $(shell find src -name '*.c')

# Object Files
OBJS = $(patsubst src/%,build/%,$(SRCS:.c=.o))

# Executable Name
EXEC = build/lagnos

# Default Target
all: _build $(EXEC)

# Ensure the build directory exists
_build:
	@mkdir -p build
	@mkdir -p $(dir $(OBJS))

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

# Phony Targets
.PHONY: all _build clean
