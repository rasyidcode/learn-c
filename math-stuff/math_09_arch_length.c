#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float deg2rad(float deg) {
    return deg * M_PI / 180.0;
}

int main(void) {
    float radius;
    float degrees;
    float radians;
    float arcLength;

    printf("Enter circle radius: ");
    scanf("%f", &radius);

    printf("Enter angle in degrees: ");
    scanf("%f", &degrees);

    // convert degrees to radians
    radians = deg2rad(degrees);

    // arc length
    // formula: s = radius * radians
    arcLength = radius * radians;

    printf("\n--- Result ---\n");
    printf("Angle in degrees : %.2f degrees\n", degrees);
    printf("Angle in radians : %.4f radians\n", radians);
    printf("Arc Length       : %.4f\n", arcLength);

    printf("\nUsing radians in math functions:\n");
    printf("sin(%.4f) = %.4f\n", radians, sinf(radians));
    printf("cos(%.4f) = %.4f\n", radians, cosf(radians));

    return 0;
}
