#include <raylib.h>

// program main entry point
int main(void) {

  // initialization
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60); // set the game to run at 60 frame-per-second

  // main game loop
  while (!WindowShouldClose()) { // detect window close button or esc key
    BeginDrawing();
    
    ClearBackground(RAYWHITE);

    DrawText("Hello, Raylib! Created my first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
  } 

  // de-initialization
  CloseWindow(); // close window and OpenGL context

  return 0;
}
