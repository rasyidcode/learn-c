#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float deg2rad(int deg) {
    return deg * M_PI / 180.0;
}

float rad2deg(float rad) {
   return rad * 180.0 / M_PI;
}

int main(void) {
    int special_angles_deg[] = { 0, 30, 45, 60, 90, 180, 360 };
    int special_angles_deg_size = sizeof(special_angles_deg) / sizeof(special_angles_deg[0]);
    float special_angles_rad[] = { 0, M_PI / 6, M_PI / 4, M_PI / 3, M_PI / 2, M_PI, 2 * M_PI };
    int special_angles_rad_size = sizeof(special_angles_rad) / sizeof(special_angles_rad[0]);

    printf("\n\n== Special Angel In Degrees ==\n\n");
    for (int i = 0; i < special_angles_deg_size; i++) {
        printf("%3d degrees = %.6f radians\n", special_angles_deg[i], deg2rad(special_angles_deg[i]));
    }

    printf("\n\n== Special Angel In Rad ==\n\n");
    for (int j = 0; j < special_angles_rad_size; j++) {
        printf("%6.6f radians = %.2f degrees\n", special_angles_rad[j], rad2deg(special_angles_rad[j]));
    }

    return 0;
}
