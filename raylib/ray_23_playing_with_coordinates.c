#include <raylib.h>
#include <stdio.h>

#define GAME_W 640
#define GAME_H 1024

int main(void) {
    InitWindow(GAME_W, GAME_H, "Raylib Playing with Coordinates");
    SetTargetFPS(60);

    Rectangle container = {.x = GAME_W * 0.05f,
                           .y = GAME_H * 0.05f,
                           .width = GAME_W * 0.90f,
                           .height = GAME_H * 0.90f};

    const float boxW = 200.0f;
    const float boxH = 180.0f;

    const float boxGap = 15.0f;

    const float totalBoxW = (2 * boxW) + (1 * boxGap);
    const float totalBoxH = (4 * boxH) + (3 * boxGap);

    const float startX = container.x + (container.width - totalBoxW) / 2.0f;
    const float startY = container.y + (container.height - totalBoxH) / 2.0f;

    Rectangle boxes[8];
    int boxesLength = sizeof(boxes) / sizeof(boxes[0]);
    for (int i = 0; i < boxesLength; i++) {
        int col = i % 2;
        int row = i / 2;

        boxes[i] = (Rectangle){
            .x = startX + col * (boxW + boxGap),
            .y = startY + row * (boxH + boxGap),
            .width = boxW,
            .height = boxH};
    }

    while (!WindowShouldClose()) {
        // Update

        // Draw
        // clang-format off
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // container
            DrawRectangleRec(container, LIGHTGRAY);
            DrawRectangleLinesEx(container, 1, DARKGRAY);

            for (int i = 0; i < boxesLength; i++) {


                DrawRectangleRec(boxes[i], Fade(RED, 0.5f));
                DrawRectangleLinesEx(boxes[i], 1, RED);
            }
        EndDrawing();
        // clang-format on
    }

    CloseWindow();
    return 0;
}
