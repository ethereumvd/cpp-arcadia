#include "block.h"
#include "raylib.h"

Block::Block() {

  cellsize = 45;
  rot_state = 0;
  colors = getcellcolors();

}

void Block::draw_block() {

  std::vector<Position> tiles = cells[rot_state];

  for(Position pos : tiles) {

    DrawRectangle(pos.row * cellsize + 1, pos.column * cellsize + 1, cellsize - 1, cellsize - 1, colors[id] );

  }
  
}
