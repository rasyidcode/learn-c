#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 1024

void DrawButton(const Rectangle bounds, const char *text, const Color color,
                const int textSize, const Color textColor) {
    Vector2 mouse = GetMousePosition();
    bool hovered = CheckCollisionPointRec(mouse, bounds);

    DrawRectangleRec(bounds, hovered ? ColorBrightness(color, 0.2f) : color);

    const Color BorderColor = ColorBrightness(color, -0.4f);
    DrawRectangleLinesEx(bounds, 4, BorderColor);

    int textWidth = MeasureText(text, textSize);

    DrawText(text, bounds.x + (bounds.width - textWidth) / 2,
             bounds.y + (bounds.height - textSize) / 2, textSize, textColor);
}

bool IsButtonClicked(Rectangle bounds) {
    Vector2 mouse = GetMousePosition();

    return CheckCollisionPointRec(mouse, bounds) &&
           IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void Calculate(double *result, double value, char operation) {
    switch (operation) {
    case '+':
        *result += value;
        break;
    case '-':
        *result -= value;
        break;
    case '*':
        *result *= value;
        break;
    case '/':
        if (value != 0)
            *result /= value;
        break;
    }
}

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Raylib Calculator");
    SetTargetFPS(60);

    const char *buttonsText[4][4] = {{"7", "8", "9", "/"},
                                     {"4", "5", "6", "*"},
                                     {"1", "2", "3", "-"},
                                     {"C", "0", "=", "+"}};
    Rectangle buttons[4][4];

    const float buttonWidth = 100;
    const float buttonHeight = 100;
    const float gap = 10;

    const float totalWidth = buttonWidth * 4 + gap * 3;
    const float totalHeight = buttonHeight * 4 + gap * 3;
    const float startX = (WIDTH - totalWidth) / 2.0f;
    const float startY = (HEIGHT - totalHeight) / 2.0f;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            buttons[i][j] = (Rectangle){startX + j * (buttonWidth + gap),
                                        startY + i * (buttonHeight + gap),
                                        buttonWidth, buttonHeight};
        }
    }

    bool showClickText = false;
    const char *clickedButtonText = "";
    const char *clickInfoText = "%s was clicked";

    char input[32] = "0";
    double result = 0;
    char operation = '0';
    bool newInput = true;

    while (!WindowShouldClose()) {
        // Update
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (IsButtonClicked(buttons[i][j])) {
                    // clickedButtonText = buttonsText[i][j];
                    // showClickText = true;

                    const char *text = buttonsText[i][j];
                    if (text[0] >= '0' && text[0] <= '9') {
                        if (newInput) {
                            strcpy(input, text);
                            newInput = false;
                        } else if (strlen(input) < 30) {
                            strcat(input, text);
                        }
                    } else if (text[0] == 'C') {
                        strcpy(input, "0");
                        result = 0;
                        operation = '0';
                        newInput = true;
                    } else if (text[0] == '=') {
                        Calculate(&result, atof(input), operation);
                        snprintf(input, sizeof(input), "%.2f", result);
                        newInput = true;
                    } else {
                        // operator check
                        result = atof(input);
                        operation = text[0];
                        newInput = true;
                    }
                }
            }
        }

        // Draw
        // clang-format off
        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < 4; i++) {
                 for (int j = 0; j < 4; j++) {
                    DrawButton(
                        buttons[i][j],
                        buttonsText[i][j],
                        BROWN,
                        48,
                        LIGHTGRAY
                    );
                 }      
            }

            //if (showClickText) {
            //    DrawText(TextFormat(clickInfoText, clickedButtonText),
            //        (WIDTH / 2.0f) - (MeasureText(clickInfoText, 36) / 2.0f),
            //        HEIGHT - 50.0f,
            //        36,
            //        BLACK
            //     );
            //}
            DrawText(
                input,
                (WIDTH / 2.0f) - (MeasureText(input, 48) / 2.0f),
                200,
                48,
                BLACK
            );
        EndDrawing();
        // clang-format on
    }

    CloseWindow();
    return 0;
}
