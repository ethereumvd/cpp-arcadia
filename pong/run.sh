#!/usr/bin/env bash

#ignore this file
#this was made just for local development

g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/pong

./bin/pong
