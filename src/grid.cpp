#include "grid.h"
#include "raylib.h"
#include "colors.h"
#include<iostream>

Grid::Grid() {
  num_rows = 20;
  num_cols = 10;
  cellsize = 45;//30 pixels
  colors = getcellcolors();
  for(int row = 0; row < num_rows; row++) {

    for(int col = 0; col < num_cols; col++) {

      grid[row][col] = 0;

    }

  }
}

// void Grid::Init() {
//   for(int row = 0; row < num_rows; row++) {
//
//     for(int col = 0; col < num_cols; col++) {
//
//       grid[row][col] = 0;
//
//     }
//
//   }
// }


void Grid::draw_grid() {
  for(int row = 0; row < num_rows; row++) {

    for(int col = 0; col < num_cols; col++) {

      // std::cout << "ddddddddd\n";
    
      int cell_col = grid[row][col];
    
      DrawRectangle(col * cellsize + 1, row * cellsize + 1, cellsize - 1, cellsize - 1, colors[cell_col]);
      

    }

  }
}

bool Grid::iscelloutside(int row, int column) {

  if(row >= 0 && row < num_rows && column >= 0 && column < num_cols ) {
    return false;
  } 
  return true;

}





