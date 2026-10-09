CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11 -Iinclude
TARGET=library
SRC=src/main.c src/book.c src/add.c src/list.c src/edit.c src/take.c src/find.c src/file.c
OBJ=$(SRC:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c include/library.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) library.dat
