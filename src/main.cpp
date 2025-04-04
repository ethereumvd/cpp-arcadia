#include "raylib.h"
#include "game.h"

const int win_width = 450;
const int win_height = 900;
const char *win_title = "raylib tetris";
const int fps = 60;//to make the game run at a fixed fps on every machine

Color darkblue = {44, 44, 127, 255};


int main() {

  InitWindow(win_width, win_height, win_title);
  SetTargetFPS(fps);

  Game game = Game();

  
  while(WindowShouldClose() == false) {

    BeginDrawing();
    ClearBackground(darkblue);
    game.draw();
    EndDrawing();

  }

  CloseWindow();
}
