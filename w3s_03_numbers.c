#include <stdio.h>

int main(void) {
    int distance = 10; // in miles
    float price = 3.4; // in dollar
    double PI = 22.0 / 7.0;

    printf("The distance is %d miles away\n", distance);
    printf("The price is %.1f dollars\n", price);
    printf("PI value is %lf\n", PI);

    float f1 = 35e3; // 35 * 10^3
    double d1 = 12e4; // 12 * 10^4

    printf("%.f\n", f1);
    printf("%.lf\n", d1);

    printf("f1 memory size: %zu bytes\n", sizeof(f1));
    printf("d1 memory size: %zu bytes\n", sizeof(d1));

    return 0;
}
