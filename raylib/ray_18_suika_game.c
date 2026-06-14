#include <raylib.h>

/*
 * Suika-style Game
 * 
 * source: https://chatgpt.com/g/g-p-697945fab49881918ed1868c000655de-build-games/c/6a2de8f1-74fc-83ec-b783-16dea76f7768
 */

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float radius;
} Fruit;

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Suika Game");

    Fruit fruit = {
        .position = { 400, 100 },
        .velocity = { 0, 0 },
        .radius = 20
    };

    const float gravity = 500.0f;

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        const float dt = GetFrameTime();

        fruit.velocity.y += gravity * dt;

        fruit.position.x += fruit.velocity.x * dt;
        fruit.position.y += fruit.velocity.y * dt;

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleV(fruit.position, fruit.radius, RED);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
