#include <raylib.h>

int main(void) {
  const int width = 600;
  const int height = 600;

  // init window and graphics context
  InitWindow(width, height, "Snake Game - Step 01");

  // set target frames per second
  SetTargetFPS(60);

  // game loop: runs until the window is closed (pressing esc or x button)
  while (!WindowShouldClose()) {
    BeginDrawing();
    
    ClearBackground(RAYWHITE);
    DrawText("Hello, Snake!", 220, 280, 20, LIGHTGRAY);

    EndDrawing();
  }

  // cleanup
  CloseWindow();

  return 0;
}
