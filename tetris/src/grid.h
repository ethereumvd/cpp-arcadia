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

private:
  int num_rows;
  int num_cols;
  int cellsize;
  std::vector<Color> colors;

};
