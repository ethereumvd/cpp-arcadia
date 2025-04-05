#include "game.h"
#include<cstdlib>
#include <raylib.h>

Game::Game() {

  grid = Grid();
  blocks = getallblocks();
  curr_block = getrandomblock();
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

void Game::handle_input() {

  int keypressed = GetKeyPressed();

  switch(keypressed) 
  {
    case KEY_LEFT:
      moveblockleft();
      break;
    case KEY_RIGHT:
      moveblockright();
      break;
    case KEY_DOWN:
      moveblockdown();
      break;
  }
 
}

void Game::moveblockleft() {

  curr_block.move(0,-1);
  if(isblockoutside()) {
    curr_block.move(0,1);
  }
  
}
void Game::moveblockright() {

  curr_block.move(0,1);
  if(isblockoutside()) {
    curr_block.move(0,-1);
  }
  
}
void Game::moveblockdown() {

  curr_block.move(1,0);
  if(isblockoutside()) {
    curr_block.move(-1,0);
  }
  
}

bool Game::isblockoutside() {
  std::vector<Position> tiles = curr_block.getcellpositions();

  for(Position item:tiles) {
    
    if(grid.iscelloutside(item.row, item.column)) {

      return true;

    }

  }
  return false;
}

