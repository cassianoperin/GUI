CC = gcc
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
BUILD_DIR = build
OBJ_NAME = gui
# LIBRARY_PATHS = -Llib
COMPILER_FLAGS = -std=c11 -Wall -O0 -g -pedantic
LINKER_FLAGS = -lsdl2

ifndef ARCH
$(error ARCH is not defined. Run with `make ARCH=mac`, win or linux)
endif

ifeq ($(ARCH),mac)
	INCLUDE_PATHS = -Ilib/nuklear -Ilib/nfd-extended
	LINKER_FLAGS += -framework AppKit -framework UniformTypeIdentifiers
	SRC_FILES += lib/nfd-extended/libnfd.a
endif

ifeq ($(ARCH),win)
$(error ARCH $(ARCH) not tested yet)
endif

ifeq (,linux)
$(error ARCH $(ARCH) not tested yet)
endif


all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)

