CXX       := g++           
CXXFLAGS  := -Wall -std=c++17
RLIBS     := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 

SRC 	  := src/main.cpp src/blocks.cpp src/colors.cpp src/game.cpp src/grid.cpp src/position.cpp src/block.cpp
TARGET 	  := bin/tetris

all : $(TARGET)

$(TARGET) : $(SRC) | bin 
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(RLIBS)

bin : 
	mkdir -p bin

run : $(TARGET)
	./$(TARGET)

clean :
	rm -f $(TARGET)

.PHONY: run all clean
