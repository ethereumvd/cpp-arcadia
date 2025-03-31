#include "grid.h"
#include "raylib.h"
#include "colors.h"

Grid::Grid() {
  num_rows = 20;
  num_cols = 10;
  cellsize = 45;//30 pixels
  colors = getcellcolors();
}

void Grid::Init() {
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
      if(row == 9 && col == 7) cell_col = 5;
      DrawRectangle(col * cellsize + 1, row * cellsize + 1, cellsize - 1, cellsize -1,colors[cell_col]);

    }

  }
}






