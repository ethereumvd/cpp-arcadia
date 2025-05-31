#include "../headers/grid.h"
#include "raylib.h"
#include "cstdlib"

Color alive_color = Color{0, 255, 0, 255};
Color ded_color = Color{55, 55, 55, 255};

Grid::Grid(int width, int height , int cellsize){

  cell_size = cellsize;
  rows = height/cellsize;
  columns = width/cellsize ;

  Initialise();
  // fill_grid();

}

void Grid::Initialise() {

  grid = std::vector<std::vector<int>>(rows, std::vector<int>(columns,0));

}

void Grid::draw_grid() {

  for(int i=0; i<rows; i++) {

    for(int j=0; j<columns; j++) {

      Color col = grid[i][j] != 0 ? alive_color : ded_color; 
      DrawRectangle(j * cell_size, i * cell_size, cell_size - 1, cell_size - 1, col);

    }

  }

}

void Grid::set_value(int row, int column, int val) {

  if(row >= 0 && row < rows && column < columns && column >= 0) {

    grid[row][column] = val;

  }

}

int Grid::get_value(int row, int column) {

  if(is_valid_cell(row, column)) {
    
    return grid[row][column];

  }
  return 0;

}

bool Grid::is_valid_cell(int row, int column) {

  if(row >= 0 && row < rows && column >= 0 && column < columns) {
    return true;
  }
  return false;

}

void Grid::fill_grid() {

  for(int i=0; i < rows ; i++) {

    for(int j=0; j < columns; j++) {

      int rand_value = GetRandomValue(0, 4);
      grid[i][j] = rand_value == 4 ? 1 : 0;//to ensure more zeroes than ones

    }

  }

}

void Grid::clear_grid() {

  for(int i=0; i<rows; i++) {

    for(int j=0; j<columns; j++) {

      grid[i][j] = 0;

    }

  }

}


void Grid::toggle_cell_val(int row, int column) {

  if(is_valid_cell(row, column)) {

    grid[row][column] = !grid[row][column];

  }

}
