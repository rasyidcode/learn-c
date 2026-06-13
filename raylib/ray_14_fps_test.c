#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

#define MOUSE_SENSITIVITY 0.003f

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game FPS Raylib");

    // Init camera
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // lock cursor
    DisableCursor();

    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    float yaw = 0.0f; // looking left/right
    float pitch = 0.0f; // looking up/down

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        // UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        Vector2 mouseDelta = GetMouseDelta();

        yaw -= mouseDelta.x * MOUSE_SENSITIVITY;
        pitch -= mouseDelta.y * MOUSE_SENSITIVITY;

        //Vector3 forward = {
        //    sinf(yaw) * cosf(pitch),
        //    sinf(pitch),
        //    cosf(yaw) * -cosf(pitch)
        //};
        Vector3 forward = {
            1.0f,
            0.0f,
            -1.0f
        };

        camera.target = Vector3Add(camera.position, forward);

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid(10, 1.0f);
            EndMode3D();

            DrawFPS(10, 10);
            DrawText(
                TextFormat("forward x=%.6f y=%.6f z=%.6f", forward.x, forward.y, forward.z),
                10,
                screenHeight - 30,
                20,
                DARKGRAY
            );
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();  

    return 0;
}
