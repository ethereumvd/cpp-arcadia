#!/usr/bin/env bash

g++ src/main.cpp src/position.cpp src/block.cpp src/game.cpp src/grid.cpp src/colors.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ../bin/tetris

./bin/tetris
