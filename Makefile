CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
DEBUG_FLAGS = -g -DDEBUG
SRC_DIR = src
BUILD_DIR = bin
TARGET_MAP = $(BUILD_DIR)/mapper
TARGET_RED = $(BUILD_DIR)/reducer
TARGET_COMBINE = $(BUILD_DIR)/combiner

# Default target
all: $(TARGET_MAP) $(TARGET_RED) $(TARGET_COMBINE)

# Rule for building mapper binary directly
$(TARGET_MAP): $(SRC_DIR)/mapper.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Rule for building reducer binary directly
$(TARGET_RED): $(SRC_DIR)/reducer.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Rule for building combiner binary directly
$(TARGET_COMBINE): $(SRC_DIR)/combiner.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Debug mode target
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean debug

