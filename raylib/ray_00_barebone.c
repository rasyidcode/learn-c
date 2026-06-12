#include <raylib.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "rectanglepro example");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
