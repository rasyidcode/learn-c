#include <raylib.h>

int main(void) {
    // Initialization
    //------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Delta Time Bouncing Ball");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    int ballRadius = 25;
    Vector2 ballPos = { ballRadius, screenHeight / 2.0f };
    float ballSpeed = 200.0f;

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        //------------------------------------------------------------
        ballPos.x += GetFrameTime() * ballSpeed;
        if (ballPos.x >= screenWidth - ballRadius) {
            ballPos.x = screenWidth - ballRadius;
            ballSpeed = ballSpeed * -1;
        } else if (ballPos.x <= ballRadius) {
            ballPos.x = ballRadius;
            ballSpeed = ballSpeed * -1;
        }

        // Draw
        //------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Draw circle with Vector2
            DrawCircleV(ballPos, ballRadius, BROWN);

            // Draw fps
            DrawText(TextFormat("FPS: %i", GetFPS()), 5, 5, 20, DARKGRAY);

            // Draw frame time
            DrawText(TextFormat("Frame time: %.2f ms", GetFrameTime() * 1000), 5, 25, 20, DARKGRAY);

            // Draw current ball position
            //DrawText(TextFormat("Ball x: %.2f", ballPos.x), 5, 45, 20, DARKGRAY);
            //DrawText(TextFormat("Ball y: %.2f", ballPos.y), 5, 65, 20, DARKGRAY);
        EndDrawing();
    }

    // De-Initialization
    //------------------------------------------------------------
    CloseWindow();  // Close window and OpenGL context

    return 0;
}
