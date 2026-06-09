#include <stdio.h>

int main(void) {
    int num = 1 / 2;
    float num2 = 1.0 / 2.0;
    int num3 = 1.4 * 2.5;
    float num4 = 1.4 * 2.5;
    float num5 = 2.0 * 3;
    int num6 = 1;
    float num7;

    num7 = num6;

    printf("int num = 1 / 2 => %d\n", num);
    printf("float num2 = 1.0 / 2.0 => %.1f\n", num2);
    printf("int num3 = 1.4 * 2.5 => %d\n", num3);
    printf("float num4 = 1.4 * 2.5 => %.1f\n", num4);
    printf("float num5 = 2.0 * 3 => %.1f\n", num5);
    printf("num7 = num6 => %.1f\n", num7);

    return 0;
}
