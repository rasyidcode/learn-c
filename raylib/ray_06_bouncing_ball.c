#include <raylib.h>

int main(void) {
    // Initialization
    //------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float ballMaxSpeed = 300.0f;

    InitWindow(screenWidth, screenHeight, "Bouncing Ball");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    float ballRadius = 25;
    Vector2 ballPos = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 ballSpeed = { 100.0f, 100.0f };

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        //------------------------------------------------------------
        ballPos.x += GetFrameTime() * ballSpeed.x;
        ballPos.y += GetFrameTime() * ballSpeed.y;
        if (ballPos.x >= screenWidth - ballRadius) {
            ballPos.x = screenWidth - ballRadius;
            ballSpeed.x *= -1.05f;
        } else if (ballPos.x <= ballRadius) {
            ballPos.x = ballRadius;
            ballSpeed.x *= -1.05f;
        }
        if (ballPos.y >= screenHeight - ballRadius) {
            ballPos.y = screenHeight - ballRadius;
            ballSpeed.y *= -1.05f;
        } else if (ballPos.y <= ballRadius) {
            ballPos.y = ballRadius;
            ballSpeed.y *= -1.05f;
        }

        if (ballSpeed.x >= ballMaxSpeed) {
            ballSpeed.x = ballMaxSpeed;
        }
        if (ballSpeed.x <= -ballMaxSpeed) {
            ballSpeed.x = -ballMaxSpeed;
        }
        if (ballSpeed.y >= ballMaxSpeed) {
            ballSpeed.y = ballMaxSpeed;
        }
        if (ballSpeed.y <= -ballMaxSpeed) {
            ballSpeed.y = -ballMaxSpeed;
        }

        // Draw
        //------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Draw circle with Vector2
            DrawCircleV(ballPos, ballRadius, BROWN);

            // Draw fps
            DrawText(TextFormat("FPS: %i", GetFPS()), 5, 5, 20, DARKGRAY);

            // Draw ball speed
            DrawText(TextFormat("Ball speed: x=%.2f y=%.2f", ballSpeed.x, ballSpeed.y), 5, 25, 20, DARKGRAY);
        EndDrawing();
    }

    // De-Initialization
    //------------------------------------------------------------
    CloseWindow();  // Close window and OpenGL context

    return 0;
}
