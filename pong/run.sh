#!/usr/bin/env bash

g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/pong

./bin/pong
