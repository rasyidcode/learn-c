#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    double degrees;    
    double radians;

    printf("Enter angle in degrees: ");
    scanf("%lf", &degrees);

    radians = degrees * M_PI / 180.0;

    printf("%.2f degrees = %.6f radians\n", degrees, radians);
    printf("sin(radians) = %.6f\n", sin(radians));
    printf("cos(radians) = %.6f\n", cos(radians));
    //printf("sin(%.2f degrees) = %.6f\n", degrees, sin(radians));
    //printf("cos(%.2f degrees) = %.6f\n", degrees, cos(radians));
    
    return 0;
}
