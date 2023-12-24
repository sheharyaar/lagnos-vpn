# Define compiler
CC := gcc

# Define compiler flags
CFLAGS := -Wall -Werror -g

# Source directories
SRC_DIRS := src/log src/tun

# Source files
SRCS := $(wildcard $(SRC_DIRS:=/*.c)) src/vpn.c

# Object files
OBJS := $(SRCS:.c=.o)

# Binary directory
BIN_DIR := bin

# Target binary
TARGET := $(BIN_DIR)/lagnos-vpn

# Default target
all: $(TARGET)

# Rule to create the binary directory
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Rule to make the target
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# PHONY target for cleaning up
.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
