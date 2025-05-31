#include "../headers/sim.h"

// Simulate::Simulate(int width, int height, int cellsize) {
//
//   grid = Grid(width, height, cellsize);
//   new_grid = Grid(width, height, cellsize);
//
// }

void Simulate::Draw() {

  grid.draw_grid();

}

void Simulate::setval(int row, int column, int val) {

  grid.set_value(row, column, val);

}

bool Simulate::is_valid(int row, int column) {

  return grid.is_valid_cell(row, column);

}

int Simulate::count_live_neighbours(int row, int column) {

  int dx[] = {1, 1, 1, 0, -1, -1 ,-1 , 0};
  int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};
  int cnt = 0;

  for(int i=0; i < 8; i++) {
    int n_row  = (row + dx[i] + grid.rows) % grid.rows;
    int n_col = (column + dy[i] + grid.columns) % grid.columns;
    
    if(is_valid(n_row, n_col) && grid.grid[n_row][n_col] != 0){

      cnt++;

    }
  }
  return cnt;

}

void Simulate::update_state() {

  if(is_running()) {
    for(int i=0; i<grid.rows; i++) {

      for(int j=0; j<grid.columns; j++) {

        int live_neighbours = count_live_neighbours(i, j);
        int cell_val = grid.get_value(i, j);

        if(cell_val == 1) {

          if(live_neighbours > 3 || live_neighbours < 2) {

            new_grid.set_value(i, j, 0);

          } else {

            new_grid.set_value(i, j, 1);

          }

        } else {

          if(live_neighbours == 3) {

            new_grid.set_value(i, j, 1);

          } else {

            new_grid.set_value(i, j, 0);

          }

        }

      }

    }
    grid = new_grid;
  }

}

bool Simulate::is_running() {

  return run;

}

void Simulate::start() {

  run = true;

}

void Simulate::stop() {

  run = false;

}

void Simulate::clear() {

  if(!is_running()) grid.clear_grid() ;

}

void Simulate::gen_random_state() {

  if(!is_running()) grid.fill_grid();

}

void Simulate::toggle_cell(int row, int col) {

  if(!is_running()) grid.toggle_cell_val(row, col);


}
