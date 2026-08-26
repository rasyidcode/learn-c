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
    InitWindow(WIDTH, HEIGHT, "Raylib Calculator");
    SetTargetFPS(60);

    const int buttonWidth = 240;
    const int buttonHeight = 90;
    const int buttonX = WIDTH / 2.0f - buttonWidth / 2.0f;
    const int buttonY = HEIGHT / 2.0f - buttonHeight / 2.0f;

    Rectangle button = {buttonX, buttonY, buttonWidth, buttonHeight};

    bool clicked = false;

    const char *clickText = "Button was clicked %d times!";
    int clickCount = 0;

    while (!WindowShouldClose()) {
        // Update
        if (IsButtonClicked(button)) {
            clicked = true;
            clickCount++;
        }

        // Draw
        // clang-format off
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawButton(button, "Click me!", GREEN, 24, BLACK);
            DrawButton(button, "Reset Count", BLUE, 24, BLACK);

            if (clicked) {
                DrawText(TextFormat(clickText, clickCount), (WIDTH / 2) - (MeasureText(clickText, 32) / 2),
                    (HEIGHT / 2) - (32 / 2) + 128, 32, LIGHTGRAY);
            }
        EndDrawing();
        // clang-format on
    }

    CloseWindow();
    return 0;
}
