#include <raylib.h>

int main(void) {
    // Initialization
    const int screenWidth = 350;
    const int screenHeight = 200;

    InitWindow(screenWidth, screenHeight, "rectanglepro example");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    int size = 25;

    Vector2 pos = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 origin = { size / 2.0f, size / 2.0f };
    Vector2 moveSpeed = { 150.0f, 150.0f };
    float rotation = 0.0f;
    float rotationSpeed = 150.0f;

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        const float dt = GetFrameTime();
        rotation += rotationSpeed * dt;
        pos.x += moveSpeed.x * dt;
        pos.y += moveSpeed.y * dt;

        if (pos.x >= screenWidth - size / 2.0f || pos.x <= size / 2.0f) {
            moveSpeed.x *= -1;
        } else if (pos.y >= screenHeight - size / 2.0f || pos.y <= size / 2.0f) {
            moveSpeed.y *= -1;
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            Rectangle rec = {
                pos.x,
                pos.y,
                size,
                size
            };
            DrawRectanglePro(rec, origin, rotation, RED);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
