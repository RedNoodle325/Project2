# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Executable name
TARGET = PJ2

# Object files
OBJS = main.o heap.o util.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp data_structures.h util.h heap.h
	$(CC) $(CFLAGS) -c main.cpp

heap.o: heap.cpp data_structures.h heap.h
	$(CC) $(CFLAGS) -c heap.cpp

util.o: util.cpp data_structures.h util.h heap.h
	$(CC) $(CFLAGS) -c util.cpp

clean:
	rm -f $(OBJS) $(TARGET)
