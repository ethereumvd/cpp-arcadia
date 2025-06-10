#include "raylib.h"
#include "../headers/colors.h"
#include "../headers/sim.h"

const int win_height = 1000;
const int win_width = 1500;
const char* win_title = "Conway's Game of Life";
const int ui_height = 0; 
const int cell_size = 10;
int fps = 12;

Font font = LoadFont("../fonts/monogram.ttf");

Color grey = {29, 29, 29, 255};

int main() {

  InitWindow(win_width, win_height + ui_height, win_title);
  SetTargetFPS(fps);
  Simulate simulate = Simulate(win_width, win_height, cell_size);

  while(!WindowShouldClose()) {

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

      Vector2 mouse_pos = GetMousePosition();
      int row = mouse_pos.y / cell_size;
      int column = mouse_pos.x / cell_size;
      simulate.toggle_cell(row, column);

    }else if(IsKeyPressed(KEY_ENTER)) {

      simulate.start();

    } else if(IsKeyPressed(KEY_SPACE)) {

      simulate.stop();

    } else if(IsKeyPressed(KEY_RIGHT)) {

      if(fps < 120) fps += 2;
      SetTargetFPS(fps);

    } else if(IsKeyPressed(KEY_LEFT)) {

      if(fps > 5) fps -= 2;
      SetTargetFPS(fps);

    } else if(IsKeyPressed(KEY_UP)) {

      simulate.gen_random_state();

    } else if(IsKeyPressed(KEY_DOWN)) {

      simulate.clear();

    }

    simulate.update_state();
    BeginDrawing();
    ClearBackground(darkgrey);
    simulate.Draw();
    EndDrawing();

  }

  CloseWindow();

}
