#include <raylib.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define GRID_SIZE     20

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game - Step 03");
  SetTargetFPS(60);

  // define a snake: 3 segments, head at (15,15), moving right
  Vector2 snake[100]; // max size
  int length = 3;

  snake[0] = (Vector2){15, 15}; // head
  snake[1] = (Vector2){14, 15};
  snake[2] = (Vector2){13, 15};

  // colors
  Color headColor = DARKGREEN;
  Color bodyColor = GREEN;

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

    // draw snake
    for (int i = 0; i < length; i++) {
      Color c = (i == 0) ? headColor : bodyColor;
      DrawRectangle(snake[i].x * GRID_SIZE, snake[i].y * GRID_SIZE, GRID_SIZE - 1, GRID_SIZE - 1, c);
    }

    // draw debug info
    DrawText("Snake static demo", 10, 10, 20, DARKGRAY);
    DrawText("Head at (15, 15), moving right", 10, 35, 20, GRAY);

    EndDrawing();
  }

  // cleanup
  CloseWindow();
  return 0;
}
