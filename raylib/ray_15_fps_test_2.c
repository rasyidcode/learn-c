#include <raylib.h>
#include <raymath.h>

#define MOUSE_SENSITIVITY 0.003f

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "FPS Tutorial - Step 1");

    Camera3D camera = { 0 };
    //camera.position = (Vector3){ 0.0f, 2.0f, 5.0f };
    //camera.position = (Vector3){ 0.0f, 10.0f, 0.0f };
    camera.position = (Vector3){ 5.0f, 1.0f, 0.0f };
    //camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };
    //camera.target = (Vector3){ 0.0f, 1.0
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f }; // top-down view
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(60);

    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        // Temporary camera movement
        if (IsKeyDown(KEY_LEFT))
            camera.position.x -= 0.1f;

        if (IsKeyDown(KEY_RIGHT))
            camera.position.x += 0.1f;

        if (IsKeyDown(KEY_UP))
            camera.position.z -= 0.1f;

        if (IsKeyDown(KEY_DOWN))
            camera.position.z += 0.1f;

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Ground
                DrawPlane(
                    (Vector3){ 0.0f, 0.0f, 0.0f },
                    (Vector2){ 20.0f, 20.0f },
                    LIGHTGRAY
                );

                // Cube
                DrawCube(
                    (Vector3){ 0.0f, 1.0f, 0.0f },
                    2.0f,
                    2.0f,
                    2.0f,
                    RED
                );

            EndMode3D();

            DrawText("Array Keys = Move Camera", 10, 10, 20, BLACK);
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
