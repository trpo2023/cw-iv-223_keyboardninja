CC = gcc
CFLAGS = -Wall -Wextra
TARGET = main
TEST_NAME = CTests

LIB_TEST = thirdparty

.PHONY: all test clean

all: $(TARGET)

$(TARGET): main.c lib/word_lib.c
	$(CC) $(CFLAGS) main.c lib/word_lib.c -o $(TARGET)

test: $(TEST_NAME)

$(TEST_NAME): $(LIB_TEST)/CTests.c $(LIB_TEST)/main.c lib/word_lib.c
	$(CC) $(CFLAGS) $(LIB_TEST)/CTests.c $(LIB_TEST)/main.c lib/word_lib.c -o $(TEST_NAME)

clean:
	rm -f $(TARGET) $(TEST_NAME)