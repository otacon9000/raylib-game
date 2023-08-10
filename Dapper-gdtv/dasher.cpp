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

    //Player
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRect;
    scarfyRect.width = scarfy.width/6;
    scarfyRect.height = scarfy.height;
    scarfyRect.x = 0;
    scarfyRect.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRect.width/2;
    scarfyPos.y = windowHeight - scarfyRect.height;

    // animation frame
    int frame{};
    // amount of time before we update the animation frame
    const float updateTime{1.0/12.0};
    float runningTime{};

    //jump
    bool isInAir{};
    const int jumpVel{-22};

    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // delta time
        const float deltaTime{GetFrameTime()};
        BeginDrawing();
        ClearBackground(WHITE);

        if (scarfyPos.y >= windowHeight - scarfyRect.height)
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

        scarfyPos.y += velocity;

        runningTime += deltaTime;
        if (runningTime >= updateTime)
        {
            runningTime = 0.0;
            // update animation frame
            scarfyRect.x = frame * scarfyRect.width;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }
        }

        DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);

        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}
