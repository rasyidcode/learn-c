#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void deg2rad(float *rad, int deg) {
    *rad = deg * M_PI / 180.0;
}

void rad2deg(int *deg, float rad) {
   *deg = round(rad * 180.0 / M_PI);
}

int main(void) {
    int deg;    
    float rad;
    int action;

    printf("\n\n=== Welcome to Degrees Radians Converter ===\n\n");
    printf("Choose action below\n");
    printf("1. Degrees to Radians\n");
    printf("2. Radians to Degrees\n\n");
    printf("Which action (1/2): ");
    scanf("%d", &action);
    printf("\n");

    switch(action) {
        case 1:
            printf("Input degrees: ");
            scanf("%d", &deg);
            deg2rad(&rad, deg);
            printf("Output radians: %.6f\n", rad);
            break;
        case 2:
            printf("Input radians: ");
            scanf("%f", &rad);
            rad2deg(&deg, rad);
            printf("Output degrees: %d\n", deg);
            break;
        default:
            printf("Invalid action\n");
            break;
    }

    return 0;
}
