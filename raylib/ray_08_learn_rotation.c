#include <raylib.h>
#include <raymath.h>

int main(void) {
    // Initialization
    //------------------------------------------------------------
    const int screenWidth = 200;
    const int screenHeight = 200;
    const char *ship[] = {
        ".MM..",
        "..R..",
        "MRRMY",
        "..R..",
        ".MM.."
    };
    const float pixelSize = 5.0f;
    const int shipRow = 5;
    const int shipCol = 5;
    const float shipWidth = shipRow * pixelSize;
    const float shipHeight = shipCol * pixelSize;

    InitWindow(screenWidth, screenHeight, "learn rotation");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    Vector2 shipPos = {
        screenWidth / 2.0f,
        screenHeight / 2.0f
    };
    float shipRot = 0.0f;

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        const float dt = GetFrameTime();
        shipRot += 60.0f * dt;

        const float radians = shipRot * DEG2RAD;
        const Vector2 pixelOrigin = { pixelSize / 2.0f, pixelSize / 2.0f };
        
        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // draw ship
            for (int row = 0; row < shipRow; row++) {
                for (int col = 0; col < shipCol; col++) {
                    Color color = BLANK;

                    switch (ship[row][col]) {
                        case 'M':
                            color = MAROON;
                            break;
                        case 'R':
                            color = RED;
                            break;
                        case 'Y':
                            color = YELLOW;
                            break;
                    }

                    if (color.a == 0) {
                        continue;
                    }

                    // find each pixel center relative to the ship size
                    Vector2 localPixelCenter = {
                        col * pixelSize + pixelSize / 2.0f - shipWidth / 2.0f,
                        row * pixelSize + pixelSize / 2.0f - shipHeight / 2.0f,
                        //col * pixelSize - shipWidth / 2.0f,
                        //row * pixelSize - shipHeight / 2.0f
                    };
                    
                    // rotation formula
                    Vector2 rotatedPixelCenter = {
                        localPixelCenter.x * cosf(radians) - localPixelCenter.y * sinf(radians),
                        localPixelCenter.x * sinf(radians) + localPixelCenter.y * cosf(radians)
                    };

                    // convert it back to window position
                    Vector2 finalPixelCenter = {
                        shipPos.x + rotatedPixelCenter.x,
                        shipPos.y + rotatedPixelCenter.y
                    };

                    Rectangle rect = {
                        finalPixelCenter.x - pixelSize / 2.0f,
                        finalPixelCenter.y - pixelSize / 2.0f,
                        pixelSize,
                        pixelSize
                    };
                    DrawRectanglePro(rect, pixelOrigin, shipRot, color);
                }
            }
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
