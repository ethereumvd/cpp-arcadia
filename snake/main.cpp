#include "raylib.h"
#include "raymath.h"
#include "colors.h"
#include "deque"
#include "directions.h"
#include <deque>

const int win_width = 900;
const int win_height = 900;
const char* win_title = "Raylib Snake";
const int fps = 60;

const int win_offset = 60;

const int cell_size = 30;
const int cell_num = 30;

int score = 0;

double update_time = 0;
const double interval = 0.2;

bool Event_triggered(double interval) {
    double curr_time = GetTime();
    if(curr_time - update_time >= interval) {
        update_time = curr_time;
        return true;
    }
    return false;
}


class Food {

public:
    Vector2 food_pos ;

    Food(std::deque<Vector2> snake_body) {
        food_pos = GenerateRandomFood(snake_body);
    }

    void DrawFood() {
        float food_x = food_pos.x;
        float food_y = food_pos.y;
        Rectangle food_cell = Rectangle{food_x * cell_size + win_offset, food_y * cell_size + win_offset, cell_size, cell_size};

        DrawRectangleRounded(food_cell, 1, 50, darkgrey);
    }

    Vector2 GenerateRandomCell() {

        float x = GetRandomValue(0, cell_num - 1);
        float y = GetRandomValue(0, cell_num - 1);
        return Vector2{x, y};
    }

    bool CheckFoodOverlap(std::deque<Vector2> snake_body) {

        for(Vector2 snake_cell : snake_body) {
            if(Vector2Equals(snake_cell, food_pos)) {
                return true;
            }
        }
        return false;

    }

    Vector2 GenerateRandomFood(std::deque<Vector2> snake_body) {

        food_pos = GenerateRandomCell();

        while (CheckFoodOverlap(snake_body)) {

            food_pos = GenerateRandomCell();

        }
        return food_pos;
    }


};

class Snake {

public:
    std::deque<Vector2> snake_body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool segment_added = false; 

    void DrawSnake() {
        for(Vector2 snake_cell : snake_body) {
            float cell_x = snake_cell.x;
            float cell_y = snake_cell.y;
            Rectangle cell = Rectangle{cell_x * cell_size + win_offset, cell_y * cell_size + win_offset, cell_size, cell_size};

            DrawRectangleRounded(cell, 0.5, 20, cyan);
        }
    }

    void UpdatePos() {

        Vector2 snake_head = snake_body[0];
        Vector2 new_head = Vector2Add(snake_head , direction);
        snake_body.push_front(new_head);

        if(segment_added) {

            segment_added = false;

        } else {

            snake_body.pop_back();
        }
    }

    void ResetSnake() {
        snake_body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    }

};

class Game {

public:
    Snake snake = Snake();
    Food food = Food(snake.snake_body);
    bool over = false;

    Game() {
        score = 0;
    }

    void Draw() {
        food.DrawFood();
        snake.DrawSnake();
    }

    void Update() {

        if(!over) {

            snake.UpdatePos();
            CheckFoodCollision();
            CheckWallCollision();
            CheckBodyCollision();
        }

    }

    void CheckFoodCollision() {
        Vector2 snake_head = snake.snake_body[0];

        if(Vector2Equals(snake_head, food.food_pos)) {

            food.GenerateRandomFood(snake.snake_body);
            snake.segment_added = true;
            score++;

        }
    }

    void CheckWallCollision() {
    
        Vector2 new_head = Vector2Add(snake.snake_body[0], snake.direction);

        if(new_head.x == -2 || new_head.x > cell_num || new_head.y == -2 || new_head.y > cell_num) {

            GameReset();

        }

    }

    void CheckBodyCollision() {

        Vector2 snake_head = snake.snake_body[0];
        Vector2 new_snake_head = Vector2Add(snake_head , snake.direction);

        for(Vector2 snake_cell:snake.snake_body) {
            if(Vector2Equals(snake_cell, snake_head)) continue;

            if(Vector2Equals(new_snake_head, snake_cell)) {

                GameReset();

            }
        }

    }

    void GameReset() {

        snake.ResetSnake();
        food.GenerateRandomFood(snake.snake_body);
        over = true;
        score = 0;

    }



};


int main() {

    InitWindow(2 * win_offset + win_width, 2 * win_offset + win_height, win_title);
    SetTargetFPS(fps);

    Game game = Game();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkblue);
        DrawRectangleLinesEx(Rectangle{(float)win_offset - 5, (float)win_offset-5, (float)cell_size* cell_num + 10, (float)cell_size*cell_num + 10}, 5, green); 
        DrawText(win_title, win_offset- 5, 10, 40,green);
        DrawText(TextFormat("Score: %i", score), win_width - 80, 10, 40, green);
        game.Draw();

        if(Event_triggered(interval)) {
            game.Update();
        }

        if(IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
            game.snake.direction = up_direction;
            game.over = false;
        } 
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
            game.snake.direction = down_direction;
            game.over = false;
        } 
        if(IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
            game.snake.direction = left_direction;
            game.over = false;
        } 
        if(IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
            game.snake.direction = right_direction;
            game.over = false;
        }


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
