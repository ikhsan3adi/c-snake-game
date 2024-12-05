CC = gcc
CFLAGS = -Iinclude
LDFLAGS = -Llib -lpdcurses
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
