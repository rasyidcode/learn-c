#include <stdio.h>

int main(void) {
    float fahr, cels;
    int lower, upper, step;

    lower = -20;      /* lower limit of the temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("%10s %10s\n", "Celsius", "Fahrenheit");
    printf("%10s %10s\n", "=======", "==========");

    cels = lower;
    while (cels <= upper) {
        fahr = cels * (9.0 / 5.0) + 32.0;
        printf("%10.0f %10.0f\n", cels, fahr);
        cels = cels + step;
    }

    return 0;
}
