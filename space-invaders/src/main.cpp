#include "raylib.h"
#include "../headers/spaceship.h"

const int win_width = 750 ;
const int win_height = 700 ;
const char* win_title = "Raylib Space Invaders";
const int fps = 60;

Color grey = {29, 29, 27, 255};

int main() {

  InitWindow(win_width, win_height,win_title);
  SetTargetFPS(fps);
  Spaceship spaceship ;

  while(!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(grey);
    spaceship.draw_spaceship();
    EndDrawing();

  }

  CloseWindow();
}
