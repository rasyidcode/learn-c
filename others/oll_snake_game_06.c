#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define GRID_SIZE     20
#define GRID_WIDTH    (SCREEN_WIDTH / GRID_SIZE)
#define GRID_HEIGHT   (SCREEN_HEIGHT / GRID_SIZE)

Vector2 spawnFood(Vector2 snake[], int length);
void initGame(Vector2 snake[], int *length, Vector2 *dir, Vector2 *food, int *score);

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game - Step 06");
  SetTargetFPS(10);

  Vector2 snake[100];
  Vector2 direction;
  Vector2 food;
  int length, score;
  bool gameOver = false;

  // init game
  srand(time(NULL));
  initGame(snake, &length, &direction, &food, &score);

  // game loop
  while (!WindowShouldClose()) {
    // Game over handling: Allow restart
    if (gameOver) {
      if (IsKeyDown(KEY_SPACE)) {
        initGame(snake, &length, &direction, &food, &score);
        gameOver = false;
      }

      // still draw the screne (with overlay), then skip update/draw
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Game Over!", 240, 260, 30, RED);
      DrawText("Press SPACE to restart", 180, 310, 20, DARKGRAY);
      DrawText(TextFormat("Score: %d", score), 250, 350, 20, BLACK);
      EndDrawing();
      continue;
    }

    // 1. INPUT: handle controls
    if (IsKeyDown(KEY_RIGHT) && direction.x == 0) direction = (Vector2){1, 0};
    else if (IsKeyDown(KEY_LEFT) && direction.x == 0) direction = (Vector2){-1, 0};
    else if (IsKeyDown(KEY_UP) && direction.y == 0) direction = (Vector2){0, -1};
    else if (IsKeyDown(KEY_DOWN) && direction.y == 0) direction = (Vector2){0, 1};

    // 2. UPDATE: move snake & check collision
    // shift body
    for (int i = length - 1; i > 0; i--) {
      snake[i] = snake[i - 1];
    }
    snake[0].x += direction.x;
    snake[0].y += direction.y;

    // wall collision -> game over
    if (snake[0].x < 0 || snake[0].x >= GRID_WIDTH || snake[0].y < 0 || snake[0].y >= GRID_HEIGHT) {
      gameOver = true;
    }

    // self collision -> game over
    for (int i = 1; i < length; i++) {
      if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
        gameOver = true;
        break;
      }
    }

    // eat food?
    if (!gameOver && snake[0].x == food.x && snake[0].y == food.y) {
      length++; // grow
      score += 10;
      food = spawnFood(snake, length); // new food
    }

    // 3. DRAW: render everything
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

    // UI: score
    DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

    // pause hint
    if (length == 3 && score == 0) {
      DrawText("Use Arrow Keys to move", 170, 550, 20, GRAY);
    }

    EndDrawing();
  }

  // cleanup
  CloseWindow();
  return 0;
}

// spawn the food randomly on the screen
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

// reset or init game state
void initGame(Vector2 snake[], int *length, Vector2 *dir, Vector2 *food, int *score) {
  *length = 3;
  snake[0] = (Vector2){GRID_WIDTH / 2, GRID_HEIGHT / 2};
  snake[1] = (Vector2){snake[0].x - 1, snake[0].y};
  snake[2] = (Vector2){snake[0].x - 2, snake[0].y};
  *dir = (Vector2){1, 0}; // right
  *food = spawnFood(snake, *length);
  *score = 0;
}
