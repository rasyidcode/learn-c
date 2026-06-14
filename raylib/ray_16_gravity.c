#include <raylib.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "gravity");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    float gravity = 400.0f;
    int yPos = 30;

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        const float dt = GetFrameTime();
        yPos += gravity * dt;

        if (yPos >= screenHeight - 20) {
            yPos = screenHeight - 20;
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircle(screenWidth / 2.0f - 10, yPos, 20, RED);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
