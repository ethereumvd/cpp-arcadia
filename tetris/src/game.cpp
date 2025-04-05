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
      move_block_left();
      break;
    case KEY_RIGHT:
      move_block_right();
      break;
    case KEY_DOWN:
      move_block_down();
      break;
    case KEY_UP:
      rotate_block();
      break;
  }
 
}

void Game::move_block_left() {

  curr_block.move(0,-1);
  if(is_block_outside()) {
    curr_block.move(0,1);
  }
  
}
void Game::move_block_right() {

  curr_block.move(0,1);
  if(is_block_outside()) {
    curr_block.move(0,-1);
  }
  
}
void Game::move_block_down() {

  curr_block.move(1,0);
  if(is_block_outside()) {
    curr_block.move(-1,0);
  }
  
}

bool Game::is_block_outside() {
  std::vector<Position> tiles = curr_block.getcellpositions();

  for(Position item:tiles) {
    
    if(grid.iscelloutside(item.row, item.column)) return true;

  }
  return false;
}

void Game::rotate_block() {

  curr_block.rotate();

  // if(is_block_outside()) {
  //
  //   curr_block.undo_rotate();
  //
  // }
  
  //wall kicks like srs (super rotation system)
  if(is_block_outside()) {

    curr_block.move(0,-1);//try to shift left by 1

    if(is_block_outside()) {
      
      curr_block.move(0,2); //try to shift right by 2

      if(is_block_outside()) {

        curr_block.move(0,-1); //revert to original position
        curr_block.undo_rotate(); //still not valid then undo rotation

      }

    }

  }

}

