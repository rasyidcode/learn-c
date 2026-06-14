#include <raylib.h>

typedef struct {
    float x;
    float y;

    float velocityY;

    float width;
    float height;
} Player;

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Gravity");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    Player player = {
        400, 100, 0, 50, 50
    };

    const float gravity = 1000.0f;
    const float floorY = 400.0f;

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        const float dt = GetFrameTime();

        player.velocityY += gravity * dt;
        player.y += player.velocityY * dt;

        if (player.y + player.height > floorY) {
            player.y = floorY - player.height;
            player.velocityY = 0;
        }

        if (IsKeyPressed(KEY_SPACE) && player.y + player.height >= floorY) {
            player.velocityY = -500.0f;
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangle(
                (int)player.x,
                (int)player.y,
                (int)player.width,
                (int)player.height,
                BLUE
            );

            DrawLine(0, floorY, 800, floorY, GRAY);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
