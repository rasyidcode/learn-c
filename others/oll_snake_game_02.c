#include <raylib.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define GRID_SIZE     20

int main(void) {
  // init window and graphics context
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game - Step 02");

  // set target frames per second
  SetTargetFPS(60);

  // game loop: runs until the window is closed (pressing esc or x button)
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // draw vertical grid lines
    for (int x = 0; x <= SCREEN_WIDTH; x += GRID_SIZE) {
      DrawLine(x, 0, x, SCREEN_HEIGHT, LIGHTGRAY);
    }

    // draw horizontal grid lines
    for (int y = 0; y <= SCREEN_HEIGHT; y += GRID_SIZE) {
      DrawLine(0, y, SCREEN_WIDTH, y, LIGHTGRAY);
    }

    // draw grid cell (0,0) to corner
    DrawRectangle(0, 0, GRID_SIZE, GRID_SIZE, Fade(SKYBLUE, 0.5f));

    DrawText("Grid: 20x20 px cells", 10, 10, 20, BLACK);
    DrawText("Origin: (0,0) at top-left", 10, 35, 20, DARKGRAY);

    EndDrawing();
  }

  // cleanup
  CloseWindow();
  return 0;
}
