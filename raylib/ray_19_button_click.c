#include <raylib.h>

int main(void) {
    InitWindow(800, 450, "Raylib Button Example");
    SetTargetFPS(60);

    Rectangle button = { 300, 180, 200, 60 };
    bool clicked = false;

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        bool hovering = CheckCollisionPointRec(mouse, button);

        if (hovering && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            clicked = true;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangleRec(button, hovering ? SKYBLUE : BLUE);
            DrawText("Click me", 350, 200, 24, WHITE);

            if (clicked) {
                DrawText("Button clicked!", 315, 300, 30, DARKGREEN);
            }

            DrawText(TextFormat("Mouse: %.0f, %.0f", mouse.x, mouse.y), 10, 10, 24, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
