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

void DrawStarship2(Vector2 pos) {
    const char *ship[] = {
        "...R.....",
        "..RRR....",
        ".RRDRR...",
        "YRDDDCBR",
        ".RRDRR...",
        "..RRR....",
        "...R.....",
    }; // ASCI art starship
    const int rows = 7;
    const int cols = 9;
    //const int startX = SCREEN_WIDTH / 2 - (cols * PIXEL_SIZE) / 2;
    //const int startY = SCREEN_WIDTH / 2 - (rows * PIXEL_SIZE) / 2;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
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
                    pos.x + col * PIXEL_SIZE,
                    pos.y + row * PIXEL_SIZE,
                    PIXEL_SIZE ,
                    PIXEL_SIZE,
                    color);
            }
        }
    }
}

void DrawStarship3(Vector2 pos) {
    const char *ship[] = {
        "...R.....",
        "..RRR....",
        ".RRDRR...",
        "YRDDDCBR",
        ".RRDRR...",
        "..RRR....",
        "...R.....",
    }; // ASCI art starship
    const int rows = 7;
    const int cols = 9;
    //const int startX = SCREEN_WIDTH / 2 - (cols * PIXEL_SIZE) / 2;
    //const int startY = SCREEN_WIDTH / 2 - (rows * PIXEL_SIZE) / 2;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
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
                    pos.x + col * PIXEL_SIZE,
                    pos.y + row * PIXEL_SIZE,
                    PIXEL_SIZE ,
                    PIXEL_SIZE,
                    color);
            }
        }
    }
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "fooling around");

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    const float shipWidth = 9 * PIXEL_SIZE;
    const float shipHeight = 7 * PIXEL_SIZE;

    const float minX = 0.0f;
    const float minY = 0.0f;
    const float maxX = SCREEN_WIDTH - shipWidth;
    const float maxY = SCREEN_HEIGHT - shipHeight;

    Vector2 pos = { minX, minY };
    Vector2 speed = { 100.0f, 0.0f };

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        float dt = GetFrameTime();

        pos.x += speed.x * dt;
        pos.y += speed.y * dt;

        if (pos.x >= maxX && speed.x > 0) {
            pos.x = maxX;
            speed.x = 0;
            speed.y = 100.0f;
        } else if (pos.y >= maxY && speed.y > 0) {
            pos.y = maxY;
            speed.x = -100.0f;
            speed.y = 0;
        } else if (pos.x <= minX && speed.x < 0) {
            pos.x = minX;
            speed.x = 0;
            speed.y = -100.0f;
        } else if (pos.y <= minY && speed.y < 0) {
            pos.y = minY;
            speed.x = 100.0f;
            speed.y = 0;
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // DrawStarship();
            DrawStarship2(pos);
        EndDrawing();
  }

  // Close window and OpenGL context
  CloseWindow();

  return 0;
}
