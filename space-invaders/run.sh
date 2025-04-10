#!/usr/bin/env bash

g++ src/main.cpp src/spaceship.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/space-invaders

./bin/space-invaders
