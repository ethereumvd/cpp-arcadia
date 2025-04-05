#include "raylib.h"
#include "game.h"

const int win_width = 450;
const int win_height = 900;
const char *win_title = "raylib tetris";
const int fps = 60;  

Color darkblue = {44, 44, 127, 255};

double last_update_time = 0;

bool event_triggered(double interval) {

  double curr_time = GetTime();

  if(curr_time - last_update_time >= interval) {
    last_update_time = curr_time;
    return true;
  }

  return false;
}

int main() {

  InitWindow(win_width, win_height, win_title);
  SetTargetFPS(fps);

  Game game = Game();

  
  while(WindowShouldClose() == false) {

    game.handle_input();
    if(event_triggered(0.2)) game.move_block_down();
    BeginDrawing();
    ClearBackground(darkblue);
    game.draw();
    EndDrawing();

  }

  CloseWindow();
}
