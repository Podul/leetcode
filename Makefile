# Compiler and compiler flags
CC = gcc
CFLAGS = -Iinclude -Wall

# Update the paths for source files
# Assuming the source files are now located directly in the project root directory
SRC_FILES = $(wildcard *.c)

# Test source files remain the same
TEST_SRC_FILES = $(wildcard tests/*.c)
TEST_EXEC_PREFIX = tests/

# Object files for source and test
# Since the source files are now in the root, the object file paths should also be updated
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_OBJ_FILES = $(TEST_SRC_FILES:.c=.o)

# Default target
all: $(TEST_SRC_FILES:.c=)

# Compile source files
# The 'src' target is no longer needed if source files are in the root directory

# Compile and run a specific test
$(TEST_EXEC_PREFIX)%: tests/%.o $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^
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
# Update the clean command to remove object files from the root directory
clean:
	rm -f *.o tests/*.o $(TEST_SRC_FILES:.c=)

.PHONY: all clean test
