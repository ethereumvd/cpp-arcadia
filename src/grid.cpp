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
      // if (cell_col < 0 || cell_col >= (int)colors.size()) {
      //     std::cerr << "Invalid color index: " << cell_col << std::endl;
      //     cell_col = 0;  // Default to a safe color
      // }
      DrawRectangle(col * cellsize + 1, row * cellsize + 1, cellsize - 1, cellsize - 1, colors[cell_col]);
      

    }

  }
}






