#pragma once

#include "grid.h"
#include "../src/blocks.cpp"
  
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
  bool game_over;
  int score;
  void update_score(int lines_cleared, int moved_down_points);

private:
  bool is_block_outside();
  void lock_block();
  bool block_fits();
  std::vector<Block> blocks;
  Block curr_block;
  Block next_block;
  void reset();

};
