#include <raylib.h>
#include <raymath.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "learn sin and cos");
    SetTargetFPS(60);

    Vector2 center = { screenWidth / 2.0f, screenHeight / 2.0f };
    float radius = 120.0f;
    float angle = 0.0f;

    Vector2 startPos = { center.x, center.y };
    Vector2 endPos = { center.x + radius, center.y };

    endPos.x = center.x + cosf(0.0f) * radius;

    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleLines(center.x, center.y, radius, LIGHTGRAY);

            DrawLineV(
                startPos,
                endPos,
                RED
            );

            DrawText(TextFormat("cos = %f", cosf(0.0f)), 10, screenHeight - 20, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();  

    return 0;
}
