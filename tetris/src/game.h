#pragma once

#include "grid.h"
#include "blocks.cpp"
  
class Game {

public:
  Game();
  Grid grid;
  Block getrandomblock();
  std::vector<Block> getallblocks();
  void draw();
  void handle_input();
  void moveblockleft();
  void moveblockright();
  void moveblockdown();

private:
  bool isblockoutside();
  std::vector<Block> blocks;
  Block curr_block;
  Block next_block;
  

};
