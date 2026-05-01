#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */

int main(void) {
    int celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of the temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    for (int fahr = 0; fahr <= upper; fahr += step) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
    }

    return 0;
}
