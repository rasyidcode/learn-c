#include <stdio.h>

int main(void) {
    int fahr;

    printf("%10s %10s\n", "Fahrenheit", "Celsius");
    printf("%10s %10s\n", "==========", "=======");
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%10d %10.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
