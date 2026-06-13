#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {
    int deg = 180;
    float rad = deg * PI / 180;

    printf("radians of %d deg is %.2f\n", deg, rad);

    rad = 3.14;
    deg = round(rad * 180 / PI);

    printf("degree of %.2f radian is %d\n", rad, deg);
    
    return 0;
}
