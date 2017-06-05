CXX = g++
CFLAGS = -std=c++11 -Wall -I ./include

SRCPATH = ./src/
CPP = $(SRCPATH)main.cpp $(SRCPATH)myMap.cpp $(SRCPATH)myString.cpp $(SRCPATH)myVector.cpp $(SRCPATH)get_cities.cpp $(SRCPATH)get_cities_size.cpp $(SRCPATH)region.cpp $(SRCPATH)tree.cpp $(SRCPATH)obliquely.cpp $(SRCPATH)complete_graph.cpp $(SRCPATH)line.cpp $(SRCPATH)simple_graph.cpp

EXE = ./bin/Map.exe
MKDIR = mkdir -p ./bin
BUILD = $(MKDIR) & $(CXX) $(CFLAGS) $(CPP) -o $(EXE)

build:
	$(BUILD)

run:
	./$(EXE)
