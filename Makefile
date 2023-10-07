CC = gcc
CFLAGS = -Wall -Wextra
TARGET = main
TEST_NAME = CTests

LIB_TEST = test
LIB_MAIN = src
LIB_LIB = lib
LIB_APP = app

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(LIB_MAIN)/$(LIB_APP)/main.c $(LIB_MAIN)/$(LIB_LIB)/func.h $(LIB_MAIN)/$(LIB_LIB)/word_lib.c
	$(CC) $(CFLAGS) $(LIB_MAIN)/$(LIB_APP)/main.c $(LIB_MAIN)/$(LIB_LIB)/func.h $(LIB_MAIN)/$(LIB_LIB)/word_lib.c -o $(TARGET)

test: $(TEST_NAME)

$(TEST_NAME): $(LIB_TEST)/CTests.c $(LIB_TEST)/cmain.c $(LIB_MAIN)/$(LIB_LIB)/word_lib.c
	$(CC) $(CFLAGS) $(LIB_TEST)/CTests.c $(LIB_TEST)/cmain.c $(LIB_MAIN)/$(LIB_LIB)/word_lib.c -o $(TEST_NAME)

clean:
	rm -f $(TARGET) $(TEST_NAME)