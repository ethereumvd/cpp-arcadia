#pragma once

#include<vector>
#include "raylib.h"

class Grid {

public:
  Grid();
  // void Init();
  int grid[20][10];
  void draw_grid();
  bool iscelloutside(int row, int column);
  bool iscellempty(int row, int column);
  int clear_complete_rows();

private:
  bool is_row_complete(int num_row);
  void clear_row(int row);
  void move_row_down(int row, int num_rows);
  int num_rows;
  int num_cols;
  int cellsize;
  std::vector<Color> colors;

};
