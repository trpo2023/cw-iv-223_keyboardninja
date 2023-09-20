CC = gcc
CFLAGS = -Wall -Wextra
TARGET = main

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c lib/word_lib.c -o $(TARGET)

clean:
	rm -f $(TARGET)