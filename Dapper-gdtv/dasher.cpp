#include "raylib.h"

int main()
{
    //window dimensions
    const int windowWidth{512};
    const int windowHeight{380};
    // initialize the window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // acceleration due to gravity (pixels/frame)/frame
    const int gravity{1};

    // rectangle dimensions
    const int width{50};
    const int height{80};

    //jump
    bool isInAir{};
    const int jumpVel{-22};

    int posY{windowHeight - height};
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (posY >= windowHeight - height)
        {
            velocity = 0;
            isInAir = false;
        }
        else
        {
            velocity += gravity;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        posY += velocity;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);

        EndDrawing();
    }
    CloseWindow();
}
