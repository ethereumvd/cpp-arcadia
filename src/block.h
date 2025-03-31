#pragma once

#include<vector>
#include<map>
#include "position.cpp"
#include "colors.h"

class Block {

public:
  Block();
  void draw_block();
  int id;//unique id for different blocks
  std::map<int,std::vector<Position>> cells;

private:
  int cellsize;
  int rot_state;
  std::vector<Color> colors;

};



