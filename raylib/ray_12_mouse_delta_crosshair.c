#include <raylib.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Mouse delta crosshair");
    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    Vector2 crosshair = {
        screenWidth / 2.0f,
        screenHeight / 2.0f
    };

    DisableCursor();

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        if (IsKeyPressed(KEY_TAB)) {
            if (IsCursorHidden()) {
                EnableCursor();
                SetMousePosition((int)crosshair.x, (int) crosshair.y);
            } else {
                DisableCursor();
            }
        }

        if (IsCursorHidden()) {
            Vector2 mouseDelta = GetMouseDelta();

            crosshair.x += mouseDelta.x;
            crosshair.y += mouseDelta.y;

            // keep crosshair inside the window
            if (crosshair.x < 0) crosshair.x = 0;
            if (crosshair.x > screenWidth) crosshair.x = screenWidth;
            if (crosshair.y < 0) crosshair.y = 0;
            if (crosshair.y > screenHeight) crosshair.y = screenHeight;
        } else {
            crosshair = GetMousePosition();
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Move the mouse", 10, 10, 20, DARKGRAY);
            DrawText("Crosshair position is updated using GetMouseDelta()", 10, 35, 20, GRAY);

            DrawLine(crosshair.x - 15, crosshair.y, crosshair.x + 15, crosshair.y, RED);
            DrawLine(crosshair.x, crosshair.y - 15, crosshair.x, crosshair.y + 15, RED);
            DrawCircleV(crosshair, 4, RED);

            DrawText(
                TextFormat("Delta: x %.2f, y %2.f", crosshair.x, crosshair.y),
                10, screenHeight - 30, 20, DARKGRAY
            );
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
