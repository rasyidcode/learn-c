# ray_07_fooling_around.c Notes

These notes summarize the discussion about moving and rotating the pixel-art ship in `ray_07_fooling_around.c`.

## Why `posX` Did Not Move

The original update looked like this:

```c
int posX = 0;
int moveSpeed = 1;

posX += GetFrameTime() * moveSpeed;
```

`GetFrameTime()` returns a small floating-point value. At 60 FPS, it is roughly:

```c
0.016
```

So this expression:

```c
GetFrameTime() * moveSpeed
```

was roughly:

```c
0.016 * 1
```

But `posX` was an `int`, so the decimal part was discarded. The update effectively became:

```c
posX += 0;
```

The fix is to store positions and speeds as `float`:

```c
float posX = 0.0f;
float posY = SCREEN_HEIGHT / 2.0f - (7 * PIXEL_SIZE) / 2.0f;
float moveSpeed = 60.0f;

posX += GetFrameTime() * moveSpeed;
```

If the draw function expects integers, cast when drawing:

```c
DrawStarship2((int)posX, (int)posY);
```

In the current version, using `Vector2` is also a good approach:

```c
Vector2 pos = { 0.0f, SCREEN_HEIGHT / 2.0f - (7 * PIXEL_SIZE) / 2.0f };
Vector2 speed = { 100.0f, 0.0f };
```

## Integer Division Warning

This warning:

```text
Result of integer division used in a floating point context; possible loss of precision
```

happens because this expression uses integer division:

```c
SCREEN_HEIGHT / 2 - (7 * PIXEL_SIZE) / 2
```

All values are integers, so C performs integer math first. Only after that is the result converted to `float`.

Example:

```c
float x = 5 / 2;
```

This gives:

```c
2.0f
```

not:

```c
2.5f
```

The fix is to use float literals:

```c
float posY = SCREEN_HEIGHT / 2.0f - (7 * PIXEL_SIZE) / 2.0f;
```

Or make it clearer:

```c
float shipHeight = 7.0f * PIXEL_SIZE;
float posY = SCREEN_HEIGHT / 2.0f - shipHeight / 2.0f;
```

## Moving Around The Edge Of The Screen

The ship dimensions are:

```c
const float shipWidth = 9 * PIXEL_SIZE;
const float shipHeight = 7 * PIXEL_SIZE;
```

The screen boundaries for the ship's top-left position are:

```c
const float minX = 0.0f;
const float minY = 0.0f;
const float maxX = SCREEN_WIDTH - shipWidth;
const float maxY = SCREEN_HEIGHT - shipHeight;
```

Start at the top-left, moving right:

```c
Vector2 pos = { minX, minY };
Vector2 speed = { 100.0f, 0.0f };
```

Each frame:

```c
float dt = GetFrameTime();

pos.x += speed.x * dt;
pos.y += speed.y * dt;
```

Then turn at each edge:

```c
if (pos.x >= maxX && speed.x > 0) {
    pos.x = maxX;
    speed.x = 0.0f;
    speed.y = 100.0f;
} else if (pos.y >= maxY && speed.y > 0) {
    pos.y = maxY;
    speed.x = -100.0f;
    speed.y = 0.0f;
} else if (pos.x <= minX && speed.x < 0) {
    pos.x = minX;
    speed.x = 0.0f;
    speed.y = -100.0f;
} else if (pos.y <= minY && speed.y < 0) {
    pos.y = minY;
    speed.x = 100.0f;
    speed.y = 0.0f;
}
```

This makes the ship move:

```text
top-left -> top-right -> bottom-right -> bottom-left -> top-left
```

Clamping the position is important:

```c
pos.x = maxX;
pos.y = maxY;
pos.x = minX;
pos.y = minY;
```

Without this, frame timing can make the ship drift slightly past the edge.

## Real Rotation

`DrawRectangle()` cannot rotate. It always draws rectangles aligned to the screen.

For real rotation, use `DrawRectanglePro()`.

The idea is:

1. Find each pixel's position relative to the ship center.
2. Rotate that relative position.
3. Move it back into world/screen position.
4. Draw the pixel there.

Useful direction angles for the current ship:

```c
0.0f     // right
90.0f    // down
180.0f   // left
270.0f   // up
```

The 2D rotation formula is:

```c
rotatedX = local.x * cos(angle) - local.y * sin(angle);
rotatedY = local.x * sin(angle) + local.y * cos(angle);
```

In C:

```c
float radians = rotationDegrees * DEG2RAD;

Vector2 rotated = {
    local.x * cosf(radians) - local.y * sinf(radians),
    local.x * sinf(radians) + local.y * cosf(radians)
};
```

Then draw with `DrawRectanglePro()`:

```c
Rectangle rect = {
    finalCenter.x - PIXEL_SIZE / 2.0f,
    finalCenter.y - PIXEL_SIZE / 2.0f,
    PIXEL_SIZE,
    PIXEL_SIZE
};

Vector2 origin = {
    PIXEL_SIZE / 2.0f,
    PIXEL_SIZE / 2.0f
};

DrawRectanglePro(rect, origin, rotationDegrees, color);
```

This is a real game-development math topic. It is normal for it to feel like a lot at first.

## Simpler Alternative: Four Sprites

For the current movement, real rotation is not required.

Because the ship only moves in four directions, it can use four different sprite shapes instead:

```c
right
down
left
up
```

Use a direction variable:

```c
int direction = 0;
```

For example:

```c
0 = right
1 = down
2 = left
3 = up
```

Then update the direction when the ship turns:

```c
direction = 1; // down
direction = 2; // left
direction = 3; // up
direction = 0; // right
```

Draw based on direction:

```c
switch (direction) {
    case 0:
        DrawStarshipRight(pos);
        break;
    case 1:
        DrawStarshipDown(pos);
        break;
    case 2:
        DrawStarshipLeft(pos);
        break;
    case 3:
        DrawStarshipUp(pos);
        break;
}
```

This is a valid approach. Many games use different sprites for different directions instead of rotating one image mathematically.

## Suggested Learning Path

For this exercise, a good order is:

1. Move with `Vector2`.
2. Handle screen boundaries.
3. Store movement direction as state.
4. Draw different sprite frames for each direction.
5. Learn real rotation later.

Rotation is one of the first places where 2D game programming starts using more math. It is fine to avoid it temporarily while still building the movement behavior.
