CC = gcc -g -Wall
CFLAGS_WINDOWS = -Iinclude
CFLAGS_LINUX_MAC =
LDFLAGS_WINDOWS = -Llib -lpdcurses # pdcurses di Windows
LDFLAGS_LINUX_MAC = -lncurses # ncurses di Linux/MacOS

# Deteksi os (Linux/MacOS/Windows)
UNAME_S := $(shell uname -s)

# CFLAGS dan LDFLAGS sesuai dengan os
# Windows (default)
CFLAGS = $(CFLAGS_WINDOWS)
LDFLAGS = $(LDFLAGS_WINDOWS)

ifeq ($(UNAME_S), Linux)  # Linux
	CFLAGS = $(CFLAGS_LINUX_MAC)
	LDFLAGS = $(LDFLAGS_LINUX_MAC)
endif
ifeq ($(UNAME_S), Darwin) # macOS
	CFLAGS = $(CFLAGS_LINUX_MAC)
	LDFLAGS = $(LDFLAGS_LINUX_MAC)
endif

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = snake

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
