#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void deg2rad_pt(float *rad, int deg) {
    *rad = deg * M_PI / 180.0;
}

int main(void) {
    int deg;    
    float rad;

    printf("Enter angle in degrees: ");
    scanf("%d", &deg);

    deg2rad_pt(&rad, deg);

    printf("%d degrees = %.6f radians\n", deg, rad);

    return 0;
}
