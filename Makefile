CC = gcc
CFLAGS_WINDOWS = -Iinclude
CFLAGS_LINUX_MAC =
LDFLAGS_WINDOWS = -Llib -lpdcurses # Gunakan pdcurses di Windows
LDFLAGS_LINUX_MAC = -lncurses # Gunakan ncurses di Linux/MacOS

# Deteksi platform (Linux/MacOS/Windows)
UNAME_S := $(shell uname -s)

# Tentukan LDFLAGS sesuai dengan platform
ifeq ($(UNAME_S), Linux)  # Untuk Linux
		CFLAGS = $(CFLAGS_LINUX_MAC)
    LDFLAGS = $(LDFLAGS_LINUX_MAC)
endif
ifeq ($(UNAME_S), Darwin) # Untuk macOS
		CFLAGS = $(CFLAGS_LINUX_MAC)
    LDFLAGS = $(LDFLAGS_LINUX_MAC)
endif
ifeq ($(findstring CYGWIN,$(UNAME_S)),CYGWIN) # Untuk Windows
		CFLAGS = $(CFLAGS_WINDOWS)
    LDFLAGS = $(LDFLAGS_WINDOWS)
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
	rm -f $(OBJ) $(TARGET)
