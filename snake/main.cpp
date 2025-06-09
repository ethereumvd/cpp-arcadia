#include "raylib.h"
#include "colors.h"
#include "deque"

const int win_width = 900;
const int win_height = 900;
const char* win_title = "Raylib Snake";
const int fps = 60;

const int cell_size = 30;
const int cell_num = 30;


class Food {

public:
    Vector2 food_pos ;

    Food() {
        food_pos = GenerateRandomFood();
    }

    void DrawFood() {
        float food_x = food_pos.x;
        float food_y = food_pos.y;
        Rectangle food_cell = Rectangle{food_x * cell_size, food_y * cell_size, cell_size, cell_size};

        DrawRectangleRounded(food_cell, 1, 50, red);
    }

    Vector2 GenerateRandomFood() {

        float x = GetRandomValue(0, cell_num - 1);
        float y = GetRandomValue(0, cell_num - 1);
        return Vector2{x, y};

    }

    void MoveRight() {

    }

};

class Snake {

public:
    std::deque<Vector2> snake_body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};

    void DrawSnake() {
        for(Vector2 snake_cell : snake_body) {
            float cell_x = snake_cell.x;
            float cell_y = snake_cell.y;
            Rectangle cell = Rectangle{cell_x * cell_size, cell_y * cell_size, cell_size, cell_size};

            DrawRectangleRounded(cell, 0.5, 20, cyan);
        }
    }

};


int main() {

    InitWindow(win_width, win_height, win_title);
    SetTargetFPS(fps);

    Food food = Food();
    Snake snake = Snake();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkblue);
        food.DrawFood();
        snake.DrawSnake();



        EndDrawing();
    }

    CloseWindow();

    return 0;
}
