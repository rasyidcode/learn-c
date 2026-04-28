#include <raylib.h>
#include <stdbool.h> // for bool type (C99+)
#include <stdio.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600
#define GRID_SIZE     20 // size of one square (snake part, food)
#define GRID_WIDTH    (SCREEN_WIDTH / GRID_SIZE)
#define GRID_HEIGHT   (SCREEN_HEIGHT / GRID_SIZE)

//typedef struct {
//  int x, y;
//} Vector2;

// game state
Vector2 snake[100];         // max segments
int snakeLength = 3;        // initial length
Vector2 food;
Vector2 direction = {1, 0}; // initial direction: moving right (x+1)
bool gameRunning = true;
int score = 0;

void initGame(void);
void spawnFood(void);
void updateGame(void);
void drawGame(void);

int main(void) {
  // Initialize window and raylib
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game - Raylib");
  SetTargetFPS(10); // Game speed: 10 frames per second

  initGame();

  // Game loop
  while (!WindowShouldClose()) {
    updateGame(); 
    drawGame();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}

void initGame(void) {
  // start snake in the middle, moving right
  int startX = GRID_WIDTH / 2;
  int startY = GRID_HEIGHT / 2;

  snake[0] = (Vector2){startX, startY};
  snake[1] = (Vector2){startX - 1, startY};
  snake[2] = (Vector2){startX - 2, startY};

  snakeLength = 3;
  direction = (Vector2){1, 0}; // right
  score = 0;
  spawnFood();
}

// function to place food at random grid position (not on snake)
void spawnFood(void) {
  bool validPosition = false;
  while (!validPosition) {
    food.x = GetRandomValue(0, GRID_WIDTH - 1);
    food.y = GetRandomValue(0, GRID_HEIGHT - 1);

    // check if food spawned on snake body
    validPosition = true;
    for (int i = 0; i < snakeLength; i++) {
      if (snake[i].x == food.x && snake[i].y == food.y) {
        validPosition = false;
        break;
      }
    }
  }
}

void updateGame(void) {
  if (!gameRunning) return;

  // get keyboard input
  if (IsKeyDown(KEY_RIGHT) && direction.x == 0) {
    direction = (Vector2){1, 0}; // right
  } else if (IsKeyDown(KEY_LEFT) && direction.x == 0) {
    direction = (Vector2){-1, 0}; // left
  } else if (IsKeyDown(KEY_UP) && direction.y == 0) {
    direction = (Vector2){0, -1}; // up
  } else if (IsKeyDown(KEY_DOWN) && direction.y == 0) {
    direction = (Vector2){0, 1}; // down
  }

  // move snake head
  Vector2 head = snake[0];
  head.x += direction.x;
  head.y += direction.y;

  // check wall collision -> game over
  if (head.x < 0 || head.x >= GRID_WIDTH || head.y < 0 || head.y >= GRID_HEIGHT) {
    gameRunning = false;
    return;
  }

  // check self-collision -> game over
  for (int i = 0; i < snakeLength; i++) {
    if (snake[i].x == head.x && snake[i].y == head.y) {
      gameRunning = false;
      return;
    }
  }

  // add new head
  for (int i = snakeLength; i > 0; i--) {
    snake[i] = snake[i - 1]; // shift all segments forward
  }
  snake[0] = head; // place new head

  // check if food eaten
  if (head.x == food.x && head.y == food.y) {
    snakeLength++; // grow
    score += 10;
    spawnFood();
  }
}

// draw the game (snake, food, UI)
void drawGame(void) {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  // draw food
  DrawRectangle(food.x * GRID_SIZE, food.y * GRID_SIZE, GRID_SIZE - 1, GRID_SIZE - 1, RED);

  // draw snake
  for (int i = 0; i < snakeLength; i++) {
    Color color = (i == 0) ? DARKGREEN : GREEN; // head = darker green
    DrawRectangle(snake[i].x * GRID_SIZE, snake[i].y * GRID_SIZE, GRID_SIZE - 1, GRID_SIZE - 1, color);
  }

  // draw UI
  DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

  if (!gameRunning) {
    // game over screen
    int msgWidth = MeasureText("GAME OVER", 40);
    DrawText("GAME OVER", (SCREEN_WIDTH - msgWidth) / 2, SCREEN_HEIGHT / 2 - 20, 40, DARKBLUE);
    DrawText("Press SPACE to restart", SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2 + 30, 20, GRAY);

    // reset if space pressed
    if (IsKeyDown(KEY_SPACE)) {
      initGame();
      gameRunning = true;
    }
  }

  EndDrawing();
}
