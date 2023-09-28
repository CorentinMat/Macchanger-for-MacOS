

SRC_DIR =src
BUILD_DIR =./build
CC =gcc
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = macchanger




all:
	$(CC) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) && ./build/macchanger