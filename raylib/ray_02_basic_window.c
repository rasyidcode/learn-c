#include <raylib.h>

int main(void) {
    // Initialization
    //------------------------------------------------------------
    const int SCREEN_WIDTH = 500;
    const int SCREEN_HEIGHT = 500;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test Basic Window");

    const char *text = "Hello, Raylib!";
    int fontSize = 20;
    int textWidth = MeasureText(text, fontSize);
    int xPos = SCREEN_WIDTH / 2 - textWidth / 2;
    int yPos = SCREEN_HEIGHT / 2 - fontSize / 2;
    int moveSpeed = 1;

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        //------------------------------------------------------------
        // TODO: Update variables here
        //------------------------------------------------------------
        xPos += moveSpeed;
        if (xPos >= SCREEN_WIDTH - textWidth || xPos <= 0) {
            moveSpeed = moveSpeed * -1;
        } 

        // Draw
        //------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText(text, xPos, yPos, fontSize, RED);
        EndDrawing();
    }
    // De-Initialization
    //------------------------------------------------------------
    CloseWindow();  // Close window and OpenGL context
    //------------------------------------------------------------

    return 0;
}
