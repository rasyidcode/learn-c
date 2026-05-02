#include <stdio.h>

int main(void) {
    float fahr, celsius;
    int lower, upper, step;
    char fahr_heading[] = "Fahrenheit";
    char cels_heading[] = "Celcius";

    lower = 0;      /* lower limit of the temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("%s", fahr_heading);
    printf("%14s\n", cels_heading);
    printf("==========");
    printf("       =======\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f %13.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
