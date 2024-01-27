# Compiler and compiler flags
CC = gcc
CFLAGS = -I../include -Wall

# Directory containing test source files
TESTDIR = tests

# Source and executable files
SRCS = $(wildcard $(TESTDIR)/*.c)
EXECS = $(SRCS:.c=)

# Default target: just to avoid running all tests accidentally
all:
	@echo "Use 'make test' to run all tests or 'make test TEST=xxxtest' for a specific test."

# Rule to run all tests
test: $(EXECS)
ifeq ($(TEST),)
	@for test in $(EXECS); do \
		echo Running $$test; \
		./$$test; \
	done
else
	@echo Running $(TESTDIR)/$(TEST)
	@$(TESTDIR)/$(TEST)
endif

# Rule to compile each source file to an executable
$(TESTDIR)/%: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up executables
clean:
	rm -f $(EXECS)
