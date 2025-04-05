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
  void move_block_left();
  void move_block_right();
  void move_block_down();
  void rotate_block();

private:
  bool is_block_outside();
  std::vector<Block> blocks;
  Block curr_block;
  Block next_block;
  

};
