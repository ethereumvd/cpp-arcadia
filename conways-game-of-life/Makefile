CXX 	 := g++
CXXFLAGS := -Wall -std=c++17
RLIBS    := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC := src/main.cpp src/grid.cpp src/sim.cpp
TARGET := bin/game

all : $(TARGET)

$(TARGET) : $(SRC) | bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(RLIBS)

bin :
	mkdir -p bin

run : $(TARGET)
	./$(TARGET)

clean :
	rm -f $(TARGET)

.PHONY: all run clean
