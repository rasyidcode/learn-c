#include <raylib.h>

#define WIDTH 640
#define HEIGHT 1024

void DrawButton(const Rectangle bounds, const char *text, const Color color,
                const int textSize, const Color textColor) {
    Vector2 mouse = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mouse, bounds);

    DrawRectangleRec(bounds, hovered ? ColorBrightness(color, 0.2f) : color);
    DrawRectangleLinesEx(bounds, 2, BLACK);

    int textWidth = MeasureText(text, textSize);

    DrawText(text, bounds.x + (bounds.width - textWidth) / 2,
             bounds.y + (bounds.height - textSize) / 2, textSize, textColor);
}

bool IsButtonClicked(Rectangle bounds) {
    Vector2 mouse = GetMousePosition();

    return CheckCollisionPointRec(mouse, bounds) &&
        IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Raylib Button Experiment");
    SetTargetFPS(60);

    Rectangle countButton = {
        (WIDTH / 2.0f) - (240 / 2.0f),
        (HEIGHT / 2.0f) - (90 / 2.0f),
        240,
        90
    };
    Rectangle resetButton = {
        (WIDTH / 2.0f) - (240 / 2.0f),
        (HEIGHT / 2.0f) - (90 / 2.0f) + 90 + 5,
        240,
        90
    };

    bool showCountText = false;
    int clickCount = 0;
    const char *clickText = "Button was clicked %d times!";

    while (!WindowShouldClose()) {
        // Update
        if (IsButtonClicked(countButton)) {
            showCountText = true;
            clickCount++;
        }
        if (IsButtonClicked(resetButton)) {
            showCountText = false;
            clickCount = 0;
        }

        // Draw
        // clang-format off
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawButton(countButton, "Click me!", GREEN, 24, BLACK);
            DrawButton(resetButton, "Reset Count", BLUE, 24, BLACK);

            if (showCountText) {
                DrawText(
                    TextFormat(clickText, clickCount),
                    (WIDTH / 2) - (MeasureText(clickText, 32) / 2),
                    (HEIGHT / 2) + (HEIGHT / 4) - (32 / 2),
                    32,
                    LIGHTGRAY
                );
            }
        EndDrawing();
        // clang-format on
    }

    CloseWindow();
    return 0;
}
