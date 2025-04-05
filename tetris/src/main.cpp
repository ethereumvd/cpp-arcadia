#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

const int win_width = 450;
const int win_height = 900;
const char *win_title = "Tetris";
const int fps = 60;  


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

  InitWindow(win_width + 290, win_height + 20, win_title);
  SetTargetFPS(fps);

  Game game = Game();
  Font font = LoadFontEx("../fonts/monogram.ttf", 64, 0, 0);

  
  while(WindowShouldClose() == false) {

    game.handle_input();
    if(event_triggered(0.2)) game.move_block_down();
    BeginDrawing();
    ClearBackground(darkblue);
    DrawTextEx(font, "Score", {515,35}, 60, 2, WHITE);
    DrawTextEx(font, "Next", {540,320}, 60, 2, WHITE);
    if(game.game_over) {
      DrawTextEx(font, "GAME", {526,720}, 60, 2, RED);
      DrawTextEx(font, "OVER", {526,790}, 60, 2, RED);
    }
    DrawRectangleRounded({487, 120, 230, 110}, 0.3, 6, lightblue);

    char score_text[10];
    sprintf(score_text, "%d", game.score);
    Vector2 text_size = MeasureTextEx(font, score_text, 60, 2);
    DrawTextEx(font, score_text, {470 + ((230 - text_size.x)/2) ,150}, 60, 2, GREEN);

    DrawRectangleRounded({487, 400, 230, 220}, 0.3, 6, lightblue);
    game.draw();
    EndDrawing();

  }

  CloseWindow();
}
