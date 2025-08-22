PROJECT_NAME := xwm
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

SRC := $(shell find $(SRC_DIR) -type f -name '*.cpp')

LINUX_BUILD_DIR := $(BUILD_DIR)/linux
WINDOWS_BUILD_DIR := $(BUILD_DIR)/windows

LINUX_OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(LINUX_BUILD_DIR)/%.o, $(SRC))
WINDOWS_OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(WINDOWS_BUILD_DIR)/%.o, $(SRC))


.PHONY: all clean

-include $(wildcard toolchains/*.mk)

install_linux:
	cp ./build/linux/xwm /usr/local/bin/xwm

clean:
	rm -rf $(BUILD_DIR)
