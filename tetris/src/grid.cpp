#include "grid.h"
#include "raylib.h"
#include "colors.h"

Grid::Grid() {
  num_rows = 20;
  num_cols = 10;
  cellsize = 45;//30 pixels
  colors = getcellcolors();
  // for(int row = 0; row < num_rows; row++) {
  //
  //   for(int col = 0; col < num_cols; col++) {
  //
  //     grid[row][col] = 0;
  //
  //   }
  //
  // }
  Initialise();
}

void Grid::Initialise() {

  for(int row = 0; row < num_rows; row++) {

    for(int col = 0; col < num_cols; col++) {

      grid[row][col] = 0;

    }

  }

}

void Grid::draw_grid() {
  for(int row = 0; row < num_rows; row++) {

    for(int col = 0; col < num_cols; col++) {

      int cell_col = grid[row][col];
    
      DrawRectangle(col * cellsize + 11, row * cellsize + 11, cellsize - 1, cellsize - 1, colors[cell_col]);
      

    }

  }
}

bool Grid::iscelloutside(int row, int column) {

  if(row >= 0 && row < num_rows && column >= 0 && column < num_cols ) {
    return false;
  } 
  return true;

}

bool Grid::iscellempty(int row, int column) {
  
  if(grid[row][column] == 0) return true;

  return false;

}


bool Grid::is_row_complete(int row) {

  for(int col = 0; col < num_cols; col++) {

    if(grid[row][col] == 0) return false;

  }

  return true;
}

void Grid::clear_row(int row) {

  for(int col = 0; col < num_cols; col++) {

    grid[row][col] = 0;

  }

}

// void Grid::move_row_down(int row, int num_rows) {
//   if(row - num_rows < 0) return;
//
//   for(int col = 0; col < num_cols; col++) {
//
//     grid[row - num_rows][col] = grid[row][col];
//     grid[row][col] = 0;
//
//   }
//
// }
// void Grid::move_row_down(int row, int num_rows) {
//   int target_row = row + num_rows;
//
//   if (target_row >= num_rows) return;  
//
//   for (int col = 0; col < num_cols; col++) {
//     grid[row + num_rows-1][col] = grid[row][col]; // move current row down
//     grid[row][col] = 0;                          // clear current row
//   }
// }
//
int Grid::clear_complete_rows() {

  int cnt = 0;
  for(int row = num_rows - 1; row >= 0; row--) {

    if(is_row_complete(row)) {

      clear_row(row);
      cnt++;

      for(int r = row - 1; r >= 0; r--) {
        for(int c = 0; c < num_cols; c++) {
          grid[r+1][c] = grid[r][c]; 
        }
      }

      for(int c = 0; c < num_cols; c++) {
        grid[0][c] = 0;
      }

      row++;
    } 

  }

  return cnt;//to calculate score later on
}
