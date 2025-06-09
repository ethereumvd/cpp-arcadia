#include "raylib.h"
#include "colors.h"

extern const float win_width = 1300;
extern const float win_height = 800;
const char* win_title = "Raylib Pong Game";

const int fps = 60;

int player_score = 0;
int cpu_score = 0;

class Ball {

public:
    float x, y;
    int delta_x, delta_y;
    int radius;

    Ball() : x(win_width/2), y(win_height/2), delta_x(10), delta_y(10), radius(20) {}

    void DrawBall() {
        DrawCircle(x, y, radius, darkgrey);
    }

    void UpdatePos() {
        x += delta_x;
        y += delta_y;

        AvoidOutofBound();
    }

    void AvoidOutofBound() {

        if(x + radius >= win_width){
            delta_x *= -1;
            cpu_score++;
            ResetToOriginal();
        }

        if(x - radius <= 0) {
            delta_x *= -1;
            player_score++;
            ResetToOriginal();
        }

        if(y + radius >= win_height || y - radius <= 0) {
            delta_y *= -1;
        }

    }

    void ResetToOriginal() {

        x = win_width/2;
        y = win_height/2;

        int random_dir[2] = {-1, 1};
        delta_x *= random_dir[GetRandomValue(0, 1)];
        delta_y *= random_dir[GetRandomValue(0, 1)];
    }

};

class Paddle {

public :
    float width, height;
    float x, y;
    float delta_y;

    Paddle(int id) : width(25), height(120), delta_y(10) { 

        if(id == 1) { // this is cpu
            
            x = 10 ;
            y = (win_height - height) / 2;

        }

        if(id == 2) { // this is player
            
            x = win_width - width - 10;
            y = (win_height - height) / 2;
        }
    }

    void DrawPaddle() {
        DrawRectangle(x, y, width, height, cyan);
    }

    void UpdatePos() {

        if(IsKeyDown(KEY_UP)) {

            y -= delta_y;

        } 

        if(IsKeyDown(KEY_DOWN)) {

            y += delta_y;

        }

        AvoidOutofBound();
    }

    void AvoidOutofBound() {

        if(y <= 0) {
            y = 0;
        }

        if(y + height >= win_height) {
            y = win_height - height;
        }
    }
};

class CPUPaddle : public Paddle {

public:

    explicit CPUPaddle(int id = 1) : Paddle(id) {delta_y = 8;} //cpu is a bit slower than player

    void UpdatePos(Ball* ball) {

        if(ball->y > y + height/2) {
            y += delta_y;
        }

        if(ball->y < y + height/2) {
            y-= delta_y;
        }

        AvoidOutofBound();
    }

};

int main() {
    
    InitWindow(win_width, win_height, win_title);
    SetTargetFPS(fps);

    Ball* ball = new Ball();
    Paddle* player = new Paddle(2);
    CPUPaddle* cpu = new CPUPaddle();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkblue);
        DrawRectangle(win_width/2, 0, win_width/2, win_height, lightblue);
        
        ball->DrawBall();
        ball->UpdatePos();
        player->DrawPaddle();
        player->UpdatePos();
        cpu->DrawPaddle();
        cpu->UpdatePos(ball);

        if(CheckCollisionCircleRec({ball->x, ball->y}, ball->radius, {player->x, player->y, player->width, player->height})) {
            ball->delta_x *= -1;
        }

        if(CheckCollisionCircleRec({ball->x, ball->y}, ball->radius, {cpu->x, cpu->y, cpu->width, cpu->height})) {
            ball->delta_x *= -1;
        }

        DrawLine(win_width/2, 0, win_width/2, win_height, WHITE);

        DrawText(TextFormat("%i", cpu_score), win_width/4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score),win_width - win_width/4 + 20, 20, 80, WHITE);

        EndDrawing();
    }
    CloseWindow();

    delete(ball);
    delete(player);
    delete(cpu);

    return 0;
}
