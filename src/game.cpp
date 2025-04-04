#include "game.h"
#include<cstdlib>

Game::Game() {

  grid = Grid();
  blocks = getallblocks();
  curr_block = getrandomblock();
  // curr_block = IBlock();
  next_block = getrandomblock();

}

Block Game::getrandomblock()  {

 if(blocks.empty()) blocks = getallblocks();

 int rand_idx = rand() % blocks.size();
 Block rand_block = blocks[rand_idx];
 blocks.erase(blocks.begin()+rand_idx);

 return rand_block;

}

std::vector<Block> Game::getallblocks() {

 return {JBlock(), LBlock(), SBlock(), IBlock(), ZBlock(), TBlock(), OBlock()};

}

void Game::draw() {

  grid.draw_grid();
  curr_block.draw_block();

}
