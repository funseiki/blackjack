# Builds blackjack game
# Adapted from: http://mrbook.org/tutorials/make/

## Macros
# Note: may need to change compiler; using Windows, so g++ may not like file paths
CC=g++
CFLAGS=-c -Wall -std=c++11

# Files (consider using a wildcard?)
SOURCES=src/main.cpp src/blackjack.cpp src/player.cpp src/dealer.cpp src/deck.cpp

# TODO: Learn how to move the .o files (or remove after build)
OBJECTS=$(SOURCES:.cpp=.o)

# The game entry point
EXECUTABLE=bin/game.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf bin/* obj/* src/*.o
