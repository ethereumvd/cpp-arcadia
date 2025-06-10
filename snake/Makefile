CXX       := g++           
CXXFLAGS  := -Wall -std=c++17
RLIBS    := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11  

SRC       := main.cpp
TARGET	  := bin/snake

all : $(TARGET)

$(TARGET): $(SRC) | bin
	$(CXX) $(CXXFLAGS) $< -o $@ $(RLIBS)

bin :
	mkdir -p bin

run : $(TARGET)
	./$(TARGET)

clean :
	rm -rf $(TARGET)

.PHONY: all run clean
