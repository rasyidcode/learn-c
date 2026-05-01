#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */

int main(void) {
    float celsius;
    int lower, upper;

    lower = 0;      /* lower limit of the temperature table */
    upper = 100;    /* upper limit */

    for (int fahr = 0; fahr <= upper; fahr++) {
        celsius = 5.0 * (fahr - 32) / 9.0;
        printf("%d\t%.2f\n", fahr, celsius);
    }

    return 0;
}
