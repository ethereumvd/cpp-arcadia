#include "block.h"
#include "raylib.h"

Block::Block() {

  cellsize = 45;
  rot_state = 0;
  row_offset = 0;
  column_offset = 0;
  colors = getcellcolors();

}

void Block::draw_block() {

  std::vector<Position> tiles = getcellpositions();

  for(Position pos : tiles) {
    DrawRectangle(pos.column* cellsize + 1, pos.row * cellsize + 1, cellsize - 1, cellsize - 1, colors[id] );

  }
  
}

void Block::move(int rows, int columns) {

  row_offset += rows;
  column_offset += columns;

}

//my implementation
std::vector<Position> Block::getcellpositions() {

  std::vector<Position> newposition = cells[rot_state]; 

  for(Position &pos : newposition) {
    pos.row += row_offset;
    pos.column += column_offset;
  }

  return newposition;

}


// std::vector<Position> Block::getcellpositions()
// {
//     std::vector<Position> tiles = cells[rot_state];
//     std::vector<Position> movedTiles;
//     for (Position item : tiles)
//     {
//         Position newPos = Position(item.row + row_offset, item.column + column_offset);
//         movedTiles.push_back(newPos);
//     }
//     return movedTiles;
// }

