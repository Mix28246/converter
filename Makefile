CC = gcc
CXX = g++
CFLAGS = -Wall
CXXFLAGS = -Wall -std=c++11
LIBS = -lcurl

all: converter

random_cpp.o: random_cpp.cpp
	$(CXX) $(CXXFLAGS) -c random_cpp.cpp -o random_cpp.o

converters.o: converters.c converters.h
	$(CC) $(CFLAGS) -c converters.c -o converters.o

main.o: main.c converters.h
	$(CC) $(CFLAGS) -c main.c -o main.o

converter: random_cpp.o converters.o main.o
	$(CXX) random_cpp.o converters.o main.o -o converter $(LIBS)

clean:
	rm -f *.o converter

run: converter
	./converter

.PHONY: all clean run