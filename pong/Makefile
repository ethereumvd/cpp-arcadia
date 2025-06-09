CXX       := g++           
CXXFLAGS  := -Wall -std=c++17
LDLIBS    := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11  

SRC       := main.cpp      
TARGET    := bin/pong     

all: $(TARGET)

$(TARGET): $(SRC) | bin
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDLIBS)

bin:                  
	mkdir -p bin

run: $(TARGET)       
	./$(TARGET)

clean:              
	rm -f $(TARGET)

.PHONY: all run clean 
