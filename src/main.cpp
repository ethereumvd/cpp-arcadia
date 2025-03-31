#include "raylib.h"
#include "grid.h"
#include "blocks.cpp"

const int win_width = 450;
const int win_height = 900;
const char *win_title = "raylib tetris";
const int fps = 60;//to make the game run at a fixed fps on every machine

Color darkblue = {44, 44, 127, 255};

Grid grid = Grid();

int main() {

  InitWindow(win_width, win_height, win_title);
  SetTargetFPS(fps);

  TBlock block = TBlock();
  
  //when window closed or escape pressed WindowShouldClose returns true
  while(WindowShouldClose() == false) {

    BeginDrawing();

    ClearBackground(darkblue);
    grid.draw_grid();
    block.draw_block();

    EndDrawing();

  }

  CloseWindow();
}
