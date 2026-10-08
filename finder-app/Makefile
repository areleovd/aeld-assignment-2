# If CROSS_COMPILE is not set, use gcc by default
CC ?= gcc

# If CROSS_COMPILE is set, use it to prefix the compiler
CC := $(CROSS_COMPILE)gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source and target files
SRC = writer.c
OBJ = writer.o
TARGET = writer

# Default target: build the writer application
all: $(TARGET)

# Rule to build the writer application
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile the source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean