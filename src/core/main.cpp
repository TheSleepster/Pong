#include "main.hpp"

const float WINDOW_WIDTH = 1280;
const float WINDOW_HEIGHT = 640;

const float halfWindowWidth = WINDOW_WIDTH / 2;
const float halfWindowHeight = WINDOW_HEIGHT / 2;

int player1Score = 0;
int player2Score = 0;

struct ball {
    v2 pos;
    int radius = 10;
    int ballSpeedx = 8;
    int ballSpeedy = 8;

    void (*ballfunc)(int, int, float, Color) = &DrawCircle;
};

struct paddle {
    v2 paddlePos;

    void (*rectfunc)(int, int, int, int, Color) = &DrawRectangle;
};

ball ball {halfWindowWidth, halfWindowHeight};
paddle LPaddle {10, halfWindowHeight - 50};
paddle RPaddle {WINDOW_WIDTH - 35, halfWindowHeight - 50};

int main(void) {
    SetTargetFPS(60);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello, Window!");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        update();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void update() { 
    checkInput(); 
    pongDraw();
    handleCollision();
    handleUI();
}

void pongDraw() {

    ball.ballfunc(ball.pos.x, ball.pos.y, ball.radius, RAYWHITE);

    ball.pos.x += ball.ballSpeedx;
    ball.pos.y += ball.ballSpeedy;

    RPaddle.rectfunc(RPaddle.paddlePos.x, RPaddle.paddlePos.y, 20, 100, RAYWHITE);
    LPaddle.rectfunc(LPaddle.paddlePos.x, LPaddle.paddlePos.y, 20, 100, RAYWHITE);

    DrawLine(640, 0, 640, 800, RAYWHITE);
}

void checkInput() {
    if (IsKeyDown(KEY_W)) {
        LPaddle.paddlePos.y -= 10;
    }

    if (IsKeyDown(KEY_S)) {
        LPaddle.paddlePos.y += 10;
    }

    if(IsKeyDown(KEY_LEFT)) {
        RPaddle.paddlePos.y -= 10;
    }

    if(IsKeyDown(KEY_RIGHT)) {
        RPaddle.paddlePos.y += 10;
    }
}

void handleCollision() {
    if(ball.pos.x + ball.radius >= GetScreenWidth() || ball.pos.x - ball.radius <= 0) {
        ball.ballSpeedx *= -1;
        if(ball.pos.x - ball.radius <= 0) {
            player2Score ++;
            resetBall();
        }
        if(ball.pos.x + ball.radius >= GetScreenWidth()) {
            player1Score ++;
            resetBall();
        }
    }

    if(ball.pos.y + ball.radius >= GetScreenHeight() || ball.pos.y - ball.radius <= 0) {
        ball.ballSpeedy *= -1;
    }

    if(CheckCollisionCircleRec(ball.pos, ball.radius, Rectangle{RPaddle.paddlePos.x, RPaddle.paddlePos.y, 20, 100})) {
        ball.ballSpeedx *= -1;  
    }

    if(CheckCollisionCircleRec(ball.pos, ball.radius, Rectangle{LPaddle.paddlePos.x, LPaddle.paddlePos.y, 20, 100})) {
        ball.ballSpeedx *= -1;  
    }
}

void handleUI() {
    DrawText(TextFormat("%i", player1Score), WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player2Score), 3 * WINDOW_WIDTH / 4 - 20, 20, 80, WHITE);
}

void resetBall() {
    ball.pos.x = halfWindowWidth;
    ball.pos.y = halfWindowHeight;
}
