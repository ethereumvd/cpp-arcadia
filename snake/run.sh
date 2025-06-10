#!/usr/bin/env bash

#ignore this file 
#this was just made for local testing

g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/snake

./bin/snake
