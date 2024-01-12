# Compiler and compiler flags
CC = gcc
CFLAGS = -Iinclude -Wall

# Source files and object files
SRC_FILES = $(wildcard src/*.c)
TEST_SRC_FILES = $(wildcard tests/*.c)
TEST_EXEC_PREFIX = tests/

# Object files for source and test
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_OBJ_FILES = $(TEST_SRC_FILES:.c=.o)

# Default target
all: $(TEST_SRC_FILES:.c=)

# Compile source files
src: $(OBJ_FILES)

# Compile and run a specific test
$(TEST_EXEC_PREFIX)%: tests/%.o src
	$(CC) $(CFLAGS) -o $@ $< $(OBJ_FILES)
	./$@

# Compile test object files
tests/%.o: tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run all tests
test: $(TEST_SRC_FILES:.c=)
	for test in $^ ; do \
		./$$test ; \
	done

# Clean up
clean:
	rm -f src/*.o tests/*.o $(TEST_SRC_FILES:.c=)

.PHONY: all src clean test
