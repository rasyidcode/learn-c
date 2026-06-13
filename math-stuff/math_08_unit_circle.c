#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float deg2rad(int deg) {
    return deg * M_PI / 180.0;
}

int main(void) {
    for (int deg = 0; deg <= 270; deg += 90) {
        float rad = deg2rad(deg);
        rad = round(rad);
        printf("%3d degrees -> x = %.f\ty = %.f\n", deg, cos(rad), sin(rad));
    }

    return 0;
}
