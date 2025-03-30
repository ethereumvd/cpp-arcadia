#include "raylib.h"

const int width = 300;
const int height = 600;
const char *title = "raylib tetris";
const int fps = 60;//to make the game run at a fixed fps on every machine

int main() {

  InitWindow(width, height, title);
  SetTargetFPS(fps);

  while(WindowShouldClose() == false) {

    BeginDrawing();

    EndDrawing();

  }

  CloseWindow();
}
