#include <raylib.h>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 320
#define PIXEL_SIZE 5

void DrawStarship() {
  // left wings
  DrawRectangle(
    SCREEN_WIDTH / 2 - PIXEL_SIZE / 2 - PIXEL_SIZE,
    SCREEN_HEIGHT / 2 - PIXEL_SIZE / 2 - PIXEL_SIZE,
    PIXEL_SIZE,
    PIXEL_SIZE,
    RED);
  DrawRectangle(
    SCREEN_WIDTH / 2 - PIXEL_SIZE / 2,
    SCREEN_HEIGHT / 2 - PIXEL_SIZE / 2 - PIXEL_SIZE,
    PIXEL_SIZE,
    PIXEL_SIZE,
    RED);

  // body
  DrawRectangle(
    SCREEN_WIDTH / 2 - PIXEL_SIZE / 2,
    SCREEN_HEIGHT / 2 - PIXEL_SIZE / 2,
    PIXEL_SIZE,
    PIXEL_SIZE,
    RED);

  // head
  DrawRectangle(
    SCREEN_WIDTH / 2 - PIXEL_SIZE / 2 + PIXEL_SIZE,
    SCREEN_HEIGHT / 2 - PIXEL_SIZE / 2,
    PIXEL_SIZE,
    PIXEL_SIZE,
    RED);

  // right wings
  DrawRectangle(
    SCREEN_WIDTH / 2 - PIXEL_SIZE / 2,
    SCREEN_HEIGHT / 2 - PIXEL_SIZE / 2 + PIXEL_SIZE,
    PIXEL_SIZE,
    PIXEL_SIZE,
    RED);
  DrawRectangle(
    SCREEN_WIDTH / 2 - PIXEL_SIZE / 2 - PIXEL_SIZE,
    SCREEN_HEIGHT / 2 - PIXEL_SIZE / 2 + 5,
    PIXEL_SIZE,
    PIXEL_SIZE,
    RED);
}

void DrawStarship2(int posX, int posY) {
    const char *ship[] = {
        "...R.....",
        "..RRR....",
        ".RRDRR...",
        "YRDDDCBR.",
        ".RRDRR...",
        "..RRR....",
        "...R.....",
    }; // ASCI art starship
    const int rows = 7;
    const int cols = 9;
    //const int startX = SCREEN_WIDTH / 2 - (cols * PIXEL_SIZE) / 2;
    //const int startY = SCREEN_WIDTH / 2 - (rows * PIXEL_SIZE) / 2;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols - 1; col++) {
            Color color = BLANK;

            switch(ship[row][col]) {
                case 'R':
                    color = RED;
                    break;
                case 'D':
                    color = MAROON;
                    break;
                case 'C':
                    color = SKYBLUE;
                    break;
                case 'B':
                    color = BLUE;
                    break;
                case 'Y':
                    color = ORANGE;
                    break;
            }

            if (color.a != 0) { // if color alpha is 0, BLANK alpha is 0
            // if (ship[row][col] != '.') {
                DrawRectangle(
                    posX + col * PIXEL_SIZE,
                    posY + row * PIXEL_SIZE,
                    PIXEL_SIZE ,
                    PIXEL_SIZE,
                    color);
            }
        }
    }
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "fooling around");

//    const int startX = SCREEN_WIDTH / 2 - (cols * PIXEL_SIZE) / 2;
//    const int startY = SCREEN_WIDTH / 2 - (rows * PIXEL_SIZE) / 2;

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
    // Update
    //------------------------------------------------------------
    // TODO: Update variables here
    //------------------------------------------------------------

    // Draw
    //------------------------------------------------------------
    BeginDrawing();
        ClearBackground(RAYWHITE);

        // DrawStarship();
        DrawStarship2(
            0,
            SCREEN_HEIGHT / 2 - (7 * PIXEL_SIZE) / 2
        );
    EndDrawing();
  }

  // Close window and OpenGL context
  CloseWindow();

  return 0;
}
