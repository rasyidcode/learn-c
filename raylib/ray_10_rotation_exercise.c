#include <raylib.h>
#include <raymath.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "rectanglepro example");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    Vector2 center = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 local = { 80.0f, 0.0f };
    float rotation = 0.0f;

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        //float dt = GetFrameTime();
        // rotation += 60.0f * dt;
        float radians = rotation * DEG2RAD;

        Vector2 rotated = {
            local.x * cosf(radians) - local.y * sinf(radians),
            local.x * sinf(radians) + local.y * cosf(radians)
        };

        Vector2 final = {
            center.x + rotated.x,
            center.y + rotated.y
        };

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircle(center.x, center.y, 10, RED);
            DrawCircle(final.x, final.y, 10, GREEN);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
