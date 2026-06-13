#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void rad2deg(int *deg, float rad) {
   *deg = round(rad * 180.0 / M_PI);
}

int main(void) {
    int deg;    
    float rad;

    printf("Enter angle in radians: ");
    scanf("%f", &rad);

    rad2deg(&deg, rad);

    printf("%.6f radians = %d degrees\n", rad, deg);

    return 0;
}
