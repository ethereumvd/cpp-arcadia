#include "raylib.h"

int main() {

  InitWindow(300, 600, "raylib tetris");
  SetTargetFPS(70);//makes sure the game runs at the same speed on every machine

  while(WindowShouldClose() == false) {

    BeginDrawing();

    EndDrawing();

  }

  CloseWindow();
}
