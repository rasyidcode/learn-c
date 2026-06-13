#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float deg2rad(int deg) {
    return deg * M_PI / 180.0;
}

int main(void) {
    int deg;    
    float rad;

    printf("Enter angle in degrees: ");
    scanf("%d", &deg);

    rad = deg2rad(deg);

    printf("%d degrees = %.6f radians\n", deg, rad);

    return 0;
}
