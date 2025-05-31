#pragma once

#include "grid.h"

class Simulate {

public:
  Simulate(int width, int height, int cellsize)
  : grid(width, height, cellsize), new_grid(width, height, cellsize), run(false) {};
  void Draw();
  void setval(int row, int column, int val);
  int count_live_neighbours(int row, int column);
  bool is_valid(int row, int column);
  void update_state();
  bool is_running();
  void start();
  void stop();
  void gen_random_state();
  void clear();
  void toggle_cell(int row, int column);

private:
  Grid grid ;
  Grid new_grid ;
  bool run ;
  
};
