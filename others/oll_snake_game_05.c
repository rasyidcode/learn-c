#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define GRID_SIZE     20

Vector2 spawnFood(Vector2 snake[], int length);

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game - Step 03");
  SetTargetFPS(10);

  // define a snake: 3 segments, head at (15,15), moving right
  Vector2 snake[100]; // max size
  int length = 3;
  snake[0] = (Vector2){15, 15}; // head
  snake[1] = (Vector2){14, 15};
  snake[2] = (Vector2){13, 15};

  Vector2 direction = {1, 0}; // moving right
  srand(time(0));
  Vector2 food = spawnFood(snake, length);

  // game loop
  while (!WindowShouldClose()) {
    // handle input: change direction (prevent 180deg turns)
    if (IsKeyDown(KEY_RIGHT) && direction.x == 0) direction = (Vector2){1, 0};
    else if (IsKeyDown(KEY_LEFT) && direction.x == 0) direction = (Vector2){-1, 0};
    else if (IsKeyDown(KEY_UP) && direction.y == 0) direction = (Vector2){0, -1};
    else if (IsKeyDown(KEY_DOWN) && direction.y == 0) direction = (Vector2){0, 1};

    // update
    for (int i = length - 1; i > 0; i--) {
      snake[i] = snake[i - 1];
    }
    snake[0].x += direction.x;
    snake[0].y += direction.y;

    // check food collision
    if (snake[0].x == food.x && snake[0].y == food.y) {
      length++; // grow
      food = spawnFood(snake, length); // new food
    }

    // draw
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

    // draw food
    DrawRectangle(food.x * GRID_SIZE, food.y * GRID_SIZE, GRID_SIZE - 1, GRID_SIZE - 1, RED);

    // draw snake
    for (int i = 0; i < length; i++) {
      Color c = (i == 0) ? DARKGREEN : GREEN;
      DrawRectangle(snake[i].x * GRID_SIZE, snake[i].y * GRID_SIZE, GRID_SIZE - 1, GRID_SIZE - 1, c);
    }

    DrawText("Food", 10, 10, 20, BLACK);

    EndDrawing();
  }

  // cleanup
  CloseWindow();
  return 0;
}

Vector2 spawnFood(Vector2 snake[], int length) {
  Vector2 food;
  bool valid;

  do {
    valid = true;
    food.x = rand() % (SCREEN_WIDTH / GRID_SIZE);
    food.y = rand() % (SCREEN_HEIGHT / GRID_SIZE);

    // make sure food doesn't spawn on snake
    for (int i = 0; i < length; i++) {
      if (snake[i].x == food.x && snake[i].y == food.y) {
        valid = false;
        break;
      }
    }
  } while (!valid);

  return food;
}
