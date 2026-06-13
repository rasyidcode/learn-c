# Session Transcript

## User

I want to learn about radian and degree from scratch using C language, but don't write any code in this directory instead just show me the code and explanation and let me type it

## Assistant

Radians and degrees are two ways to measure angles.

**Core Idea**

A full circle is:

```text
360 degrees
2π radians
```

So:

```text
180 degrees = π radians
90 degrees  = π/2 radians
45 degrees  = π/4 radians
```

In C, math functions like `sin`, `cos`, and `tan` expect angles in **radians**, not degrees.

**Conversion Formulas**

Degrees to radians:

```text
radians = degrees * π / 180
```

Radians to degrees:

```text
degrees = radians * 180 / π
```

A simple C program you can type:

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
    double degrees;
    double radians;

    printf("Enter angle in degrees: ");
    scanf("%lf", &degrees);

    radians = degrees * M_PI / 180.0;

    printf("%.2f degrees = %.6f radians\n", degrees, radians);

    printf("sin(%.2f degrees) = %.6f\n", degrees, sin(radians));
    printf("cos(%.2f degrees) = %.6f\n", degrees, cos(radians));

    return 0;
}
```

Compile it like this:

```bash
gcc angles.c -o angles -lm
```

Run it:

```bash
./angles
```

Example input:

```text
90
```

Expected idea:

```text
90 degrees = 1.570796 radians
sin(90 degrees) = 1.000000
cos(90 degrees) = close to 0
```

The `-lm` part links the math library. Without it, functions like `sin`, `cos`, and `M_PI` may not work depending on your compiler setup.

A key thing to remember: humans often think in degrees, but C’s trig functions use radians. So when the user enters degrees, convert first, then call `sin`, `cos`, or `tan`.

## User

check my Makefile, I got compiler error on M_PI

## Assistant

I’ll inspect the Makefile and nearby C files to see how math constants and compiler flags are set, then I’ll explain the issue without changing files.

## Assistant

The Makefile is already linking the math library correctly with `-lm`; the `M_PI` error is coming from the C standard mode rather than the link step. I’m going to reproduce the exact compiler message next so the fix matches what GCC is doing here.

## Assistant

Your Makefile is fine for the math library:

```make
LDFLAGS := -lm
...
$(CC) $(DEBUG_CFLAGS) -o $@ $< $(LDFLAGS)
```

The error is not from `-lm`. It happens because this line uses strict C99:

```make
DEBUG_CFLAGS := -std=c99 -Wall -Wextra -pedantic -g -O0
```

`M_PI` is not part of the ISO C standard, so with `-std=c99 -pedantic`, GCC does not expose it from `<math.h>`.

Use your own constant, like you already did in `math_01_radian_degree_example.c`:

```c
#define PI 3.14159265358979323846
```

Then change:

```c
radians = degrees * M_PI / 180.0;
```

to:

```c
radians = degrees * PI / 180.0;
```

So the top of `math_02_radian_degree_example2.c` should be:

```c
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
```

Alternative: change the Makefile to use GNU extensions:

```make
DEBUG_CFLAGS := -std=gnu99 -Wall -Wextra -pedantic -g -O0
```

But for learning C from scratch, I’d prefer defining `PI` yourself because it teaches the formula clearly and keeps the code portable.

## User

so sin and cos takes degree as an argument?

## Assistant

No. In C, `sin()` and `cos()` take **radians**, not degrees.

So this is wrong if `degrees` is `90`:

```c
sin(90);
cos(90);
```

C will treat `90` as **90 radians**, not 90 degrees.

You must convert first:

```c
#define PI 3.14159265358979323846

double degrees = 90.0;
double radians = degrees * PI / 180.0;

printf("%f\n", sin(radians));
printf("%f\n", cos(radians));
```

For example:

```text
90 degrees = 1.570796 radians
sin(1.570796) = about 1
cos(1.570796) = about 0
```

Rule to remember:

```text
Humans often enter degrees.
C math functions use radians.
```

So: **degree input -> convert to radians -> pass to `sin()` / `cos()`**.

## User

check the math_02

## Assistant

I’ll read `math_02_radian_degree_example2.c` and build it so I can point out exactly what’s right or wrong without editing it.

## Assistant

`math_02_radian_degree_example2.c` looks correct now.

You fixed the `M_PI` issue with:

```c
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
```

That means: “if `M_PI` is not already defined by `<math.h>`, define it myself.”

This part is also correct:

```c
radians = degrees * M_PI / 180.0;
```

Then you pass `radians` to `sin()` and `cos()`:

```c
sin(radians)
cos(radians)
```

That is the right way.

One small improvement: check whether `scanf` succeeded:

```c
if (scanf("%lf", &degrees) != 1) {
    printf("Invalid input\n");
    return 1;
}
```

But for a learning example, your current file is fine.

## User

the last 2 printf is actually confused me, can you explain? you are the one who make that code by the way

## Assistant

Yes, fair point. These two lines are confusing because the label says “degrees”, but the actual value passed to `sin()` and `cos()` is `radians`.

The lines are:

```c
printf("sin(%.2f degrees) = %.6f\n", degrees, sin(radians));
printf("cos(%.2f degrees) = %.6f\n", degrees, cos(radians));
```

They mean:

```text
Show the user the original angle in degrees,
but calculate sin/cos using the converted radian value.
```

So if you type `90`, the program does this:

```c
degrees = 90.0;
radians = 90.0 * M_PI / 180.0;   // 1.570796
```

Then:

```c
sin(radians)
```

is really:

```c
sin(1.570796)
```

But the print message says:

```text
sin(90.00 degrees) = 1.000000
```

That is mathematically okay because “sin of 90 degrees” means the same angle as “sin of 1.570796 radians”.

A clearer version would be:

```c
printf("sin(%.2f degrees / %.6f radians) = %.6f\n",
       degrees, radians, sin(radians));

printf("cos(%.2f degrees / %.6f radians) = %.6f\n",
       degrees, radians, cos(radians));
```

Or even simpler for learning:

```c
printf("Converted radians: %.6f\n", radians);
printf("sin(radians) = %.6f\n", sin(radians));
printf("cos(radians) = %.6f\n", cos(radians));
```

The important idea:

```text
The printed label uses degrees because that is what the user entered.
The function call uses radians because C requires radians.
```

So the code is correct, but the wording could definitely be clearer for a beginner.

## User

What else I could learn from radian and degree

## Assistant

Here are good next things to learn, in order:

1. **Convert Both Ways**

You already did:

```c
radians = degrees * PI / 180.0;
```

Now also learn:

```c
degrees = radians * 180.0 / PI;
```

Example idea:

```text
Input radians: 3.14159
Output degrees: 180
```

2. **Special Angles**

Memorize these because they appear everywhere:

```text
0 degrees   = 0 radians
30 degrees  = PI / 6
45 degrees  = PI / 4
60 degrees  = PI / 3
90 degrees  = PI / 2
180 degrees = PI
360 degrees = 2 * PI
```

3. **Unit Circle**

The unit circle is a circle with radius `1`.

For an angle:

```c
x = cos(angle);
y = sin(angle);
```

So:

```text
cos gives the x position
sin gives the y position
```

Example:

```text
0 degrees   -> x = 1, y = 0
90 degrees  -> x = 0, y = 1
180 degrees -> x = -1, y = 0
270 degrees -> x = 0, y = -1
```

4. **Why Radians Exist**

Radians come from circle length.

Formula for arc length:

```text
arc length = radius * angle_in_radians
```

If radius is `1`, then:

```text
arc length = angle_in_radians
```

That is why radians are natural for math and programming.

5. **Use `tan()`**

After `sin()` and `cos()`, learn:

```c
tan(radians)
```

But be careful:

```text
tan(90 degrees)
```

is undefined because it tries to divide by zero internally.

6. **Build a Small Table Program**

Make a program that prints:

```text
Degrees   Radians     Sin       Cos
0         0.000000    0.000000  1.000000
30        0.523599    0.500000  0.866025
45        0.785398    0.707107  0.707107
60        1.047198    0.866025  0.500000
90        1.570796    1.000000  0.000000
```

This is a very useful beginner exercise.

7. **Draw Points on a Circle**

Later, you can use:

```c
x = center_x + radius * cos(radians);
y = center_y + radius * sin(radians);
```

That is how games, animations, clocks, wheels, and circular motion work.

The most useful next step for you is probably: **write a program that prints a degree/radian/sin/cos table from 0 to 360 degrees.**

## User

Save our conversation in this session in Markdown file at docs directory, I don't want any missing information, Put exactly what appear on the screen

## Assistant

I’ll create a `docs` directory if it is missing and write a Markdown transcript with the user-visible conversation only, preserving the wording from this session.

## Assistant

`docs` does not exist yet, so I’m adding it and creating a single transcript file. I’m including the normal chat messages and the short progress updates I sent, but not hidden command output because that is not shown to you in the chat UI.
