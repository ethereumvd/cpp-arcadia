#!/usr/bin/env bash

g++ main.cpp position.cpp block.cpp game.cpp grid.cpp colors.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ../bin/tetris
./../bin/tetris
