# Current Session Transcript

## User

```text
I want to learn about sin and cos using Raylib and C
```

## Assistant

```text
I’ll take a quick look at the project shape so the example fits how you’re already building Raylib programs.
```

## Assistant

```text
The repo is a sequence of small numbered lessons, so I’m going to add the next focused lesson as a standalone C file and wire it into the existing build style if needed.
```

## Assistant

```text
I found you’ve already touched the rotation formula in `ray_08` and `ray_10`. I’m going to make the next lesson more visual: sine and cosine as “coordinates on a circle”, with the same value driving a moving dot, projection lines, and wave graphs.
```

## Assistant

```text
The lesson file is in place. I’m compiling it now to catch C warnings, missing math symbols, or Raylib linkage issues before I hand it over.
```

## Assistant

Added a new Raylib lesson: [ray_13_learn_sin_cos.c](/home/rcd/My-Work/learn-c/raylib/ray_13_learn_sin_cos.c).

It shows `sin` and `cos` as coordinates on a circle:

```c
x = center.x + cos(angle) * radius;
y = center.y - sin(angle) * radius;
```

Use:

```bash
make build-run SRC=ray_13_learn_sin_cos.c
```

Controls:
- Hold `SPACE` to animate the angle
- Hold `LEFT` / `RIGHT` to move the angle manually

Build verification passed with:

```bash
make build SRC=ray_13_learn_sin_cos.c
```

## User

```text
Can you revert what you've added and just show me the code with explanation? I would like to type it myself
```

## Assistant

```text
I’ll remove the lesson file I added, then I’ll give you the code as a type-it-yourself example with the key ideas explained.
```

## Assistant

Removed `ray_13_learn_sin_cos.c`.

Here’s the code to type yourself:

```c
#include <math.h>
#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "learn sin and cos");
    SetTargetFPS(60);

    Vector2 center = { screenWidth / 2.0f, screenHeight / 2.0f };
    float radius = 120.0f;
    float angle = 0.0f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_SPACE)) {
            angle += 1.5f * dt;
        }

        float x = cosf(angle) * radius;
        float y = sinf(angle) * radius;

        Vector2 point = {
            center.x + x,
            center.y + y
        };

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleLines(center.x, center.y, radius, LIGHTGRAY);

            DrawLineV(center, point, BLACK);
            DrawCircleV(point, 10, RED);

            DrawLine(center.x, center.y, point.x, center.y, BLUE);
            DrawLine(point.x, center.y, point.x, point.y, GREEN);

            DrawText("Hold SPACE to increase the angle", 20, 20, 20, DARKGRAY);
            DrawText("cos(angle) controls x", 20, 50, 20, BLUE);
            DrawText("sin(angle) controls y", 20, 80, 20, GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
```

The important part is this:

```c
float x = cosf(angle) * radius;
float y = sinf(angle) * radius;
```

`cosf(angle)` gives the horizontal position around a circle.

`sinf(angle)` gives the vertical position around a circle.

Both return values between `-1.0` and `1.0`, so multiplying by `radius` makes the movement bigger.

Then this moves the point from “circle space” into screen space:

```c
Vector2 point = {
    center.x + x,
    center.y + y
};
```

So the dot is not orbiting around `(0, 0)`, it is orbiting around `center`.

Build it with:

```bash
make build-run SRC=your_file_name.c
```

## User

```text
put all the code you deleted before into a file called learn_sin_and_cos.c
```

## Assistant

```text
I’ll restore the full deleted example into `learn_sin_and_cos.c` and compile it to make sure it still builds cleanly.
```

## Assistant

```text
The file is restored under the requested name. I’m doing one build pass now so we know the copied code is valid in this repo.
```

## Assistant

Done. I restored the deleted example into [learn_sin_and_cos.c](/home/rcd/My-Work/learn-c/raylib/learn_sin_and_cos.c).

It builds cleanly with:

```bash
make build SRC=learn_sin_and_cos.c
```

Run it with:

```bash
make build-run SRC=learn_sin_and_cos.c
```

## User

```text
Save our current conversation in Markdown file on docs/ directory, make sure no information missing, I want the file contains exactly what appear on this current session
```

## Assistant

```text
I’ll create a `docs` directory and add a Markdown transcript of the session as shown here, including your requests, my responses, and the relevant command/build output summaries that appeared.
```

## Assistant

```text
I’m going to name it `docs/current-session.md` and keep the transcript chronological, with separate sections for each user and assistant message.
```
