#pragma once

#include<vector>
#include<map>
#include "position.h"
#include "colors.h"

class Block {

public:
  Block();
  void draw_block(int offset_x, int offset_y);
  void move(int rows, int columns);
  void rotate();
  void undo_rotate();
  std::vector<Position> getcellpositions();
  int id;
  int row_offset;
  int column_offset;
  std::map<int,std::vector<Position>> cells;


protected:
  int cellsize;
  int rot_state;
  std::vector<Color> colors;

};



