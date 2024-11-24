# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -g3 -I./src

# Directories
SRC_DIR = src
BIN_DIR = bin

# Source and Object Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

# Executable
MAIN_EXEC = $(BIN_DIR)/main

# Default Target
all: $(MAIN_EXEC)

# Build Main Executable
$(MAIN_EXEC): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Object File Rule
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Build Files
clean:
	rm -rf $(BIN_DIR)/*

# Clean and Rebuild
rebuild: clean all
