CC = gcc
CFLAGS = -Wall -Werror

LIBRARY_NAME = libkanlib.so

SOURCE_FILES = src/*.c
INCLUDE_FILES = include/*.h
OBJECT_FILES = *.o

all: *.o
	$(CC) -shared -o $(LIBRARY_NAME) $(OBJECT_FILES)

*.o: $(SOURCE_FILES)
	$(CC) -fPIC -c $(SOURCE_FILES)

clean:
	rm $(OBJECT_FILES) $(LIBRARY_NAME)