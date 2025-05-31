#pragma once
#include<vector>

class Grid {

public:
  Grid(int width , int height , int cellsize);
  std::vector<std::vector<int>> grid;
  void Initialise();
  void draw_grid();
  void set_value(int row, int column, int val);
  int get_value(int row, int column);
  bool is_valid_cell(int row, int column);
  int rows;
  int columns;
  int cell_size;
  void fill_grid();
  void clear_grid();
  void toggle_cell_val(int row, int column);

};
