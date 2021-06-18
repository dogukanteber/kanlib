CC = gcc
CFLAGS =
RM = rm -rf
OUT = dynamic_array

all: build

build: main.o dynamic_array.o
	$(CC) $(CFLAGS) -o $(OUT) main.c dynamic_array.c

debug: CFLAGS += -DDEBUG_ON
debug: build

main.o: main.c dynamic_array.h
	$(CC) $(CFLAGS) -c main.c

dynamic_array.o: dynamic_array.c dynamic_array.h
	$(CC) $(CFLAGS) -c dynamic_array.c

clean: 
	$(RM) *.o $(OUT)