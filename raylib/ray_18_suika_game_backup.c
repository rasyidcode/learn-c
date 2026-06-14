#include <raylib.h>

/*
 * Suika-style Game
 * 
 * source: https://chatgpt.com/g/g-p-697945fab49881918ed1868c000655de-build-games/c/6a2de8f1-74fc-83ec-b783-16dea76f7768
 */

#define MAX_FRUITS 100

typedef struct {
    Vector2 position;
    Vector2 velocity;
    float radius;
} Fruit;

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    const float gravity = 500.0f;
    const float floorY = 400.0f;


    Fruit fruits[MAX_FRUITS];
    int fruitCount = 0;

    InitWindow(screenWidth, screenHeight, "Suika Game");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        const float dt = GetFrameTime();

        // spawn fruit with left click
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (fruitCount < MAX_FRUITS) {
                fruits[fruitCount++] = (Fruit){
                    .position = { (float)GetMouseX(), 50 },
                    .velocity = { 0, 0 },
                    .radius = 25
                };
            }
        }

        // update fruits
        for (int i = 0; i < fruitCount; i++) {
            Fruit *fruit = &fruits[i];

            // gravity
            fruit->velocity.y += gravity * dt;

            // movement
            fruit->position.x += fruit->velocity.x * dt;
            fruit->position.y += fruit->velocity.y * dt;

            if (fruit->position.y + fruit->radius > floorY) {
                fruit->position.y = floorY - fruits->radius;
                fruit->velocity.y = 0;
            }
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < fruitCount; i++) {
                DrawCircleV(fruits[i].position, fruits[i].radius, RED);
            }

            DrawLine(0, floorY, screenWidth, floorY, GRAY);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
