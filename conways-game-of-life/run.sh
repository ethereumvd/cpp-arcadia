#!/usr/bin/env bash

g++ src/main.cpp src/grid.cpp src/sim.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/game

./bin/game
