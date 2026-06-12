#include <raylib.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib - GetMouseDelta example");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        Vector2 mouseDelta = GetMouseDelta();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText(TextFormat("MouseDelta x: %.2f\n\t\ty: %.2f", mouseDelta.x, mouseDelta.y), 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
