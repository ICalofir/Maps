CXX = g++
CFLAGS = -std=c++11 -Wall -I ./include

SRCPATH = ./src/
CPP = $(SRCPATH)main.cpp $(SRCPATH)create_cities.cpp $(SRCPATH)myString.cpp $(SRCPATH)myVector.cpp

EXE = ./bin/Generator.exe
MKDIR = mkdir -p ./bin
BUILD = $(MKDIR) & $(CXX) $(CFLAGS) $(CPP) -o $(EXE)

build:
	$(BUILD)

run:
	./$(EXE)
