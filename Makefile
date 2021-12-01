CC = gcc
CFLAGS = -Wall -Werror

LIBRARY_NAME = libkanlib.so

SOURCE_FILES = src/*.c
INCLUDE_FILES = include/*.h
OBJECT_FILES = *.o
TEST_FILES = test/*_test.c
TEST_OBJECT_FILES = *_test.o
MAIN_TEST_FILE = test/main.c
MAIN_TEST_OBJ_FILE = test/main

LINKERS = -lcunit -lkanlib


all: *.o
	$(CC) -shared -o $(LIBRARY_NAME) $(OBJECT_FILES)

*.o: $(SOURCE_FILES)
	$(CC) -fPIC -c $(SOURCE_FILES)

test: $(MAIN_TEST_FILE) $(TEST_OBJECT_FILES)
	$(CC) $(MAIN_TEST_FILE) $(TEST_OBJECT_FILES) -o $(MAIN_TEST_OBJ_FILE) $(LINKERS) && ./$(MAIN_TEST_OBJ_FILE)

$(TEST_OBJECT_FILES): $(TEST_FILES)
	$(CC) -c $(TEST_FILES)

clean:
	rm -rf $(OBJECT_FILES) $(LIBRARY_NAME) $(TEST_OBJECT_FILES) $(MAIN_TEST_OBJ_FILE)
