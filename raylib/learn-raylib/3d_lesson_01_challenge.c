#include <raylib.h>

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Lesson 01 - First 3D Scene");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 4.0f, 3.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.0f, 0.0f};
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);
    DisableCursor();

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawGrid(10, 1.0f);

        DrawCube((Vector3){ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, PURPLE);
        DrawCubeWires((Vector3) { 0.0f, 0.5f, 0.0f, }, 1.0f, 1.0f, 1.0f, BLACK);

        DrawCube((Vector3){ 3.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, YELLOW);
        DrawCubeWires((Vector3) { 3.0f, 0.5f, 0.0f, }, 1.0f, 1.0f, 1.0f, BLACK);

        DrawSphere((Vector3){ 4.0f, 0.5f, 4.0f }, 0.5f, BLUE);
        DrawCylinder((Vector3){ -2.0f, 0.5f, 0.0f }, 0.5f, 0.5f, 1.0f, 24, GREEN);

        EndMode3D();

        DrawText("WASD + mouse to move. Esc to quit.", 20, 20, 20, DARKGRAY);
        DrawFPS(screenWidth - 100, 20);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
