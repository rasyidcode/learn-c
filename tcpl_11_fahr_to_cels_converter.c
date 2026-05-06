#include <stdio.h>

#define UPPER   300
#define LOWER   0
#define STEP    20

int main(void) {
    printf("%10s %10s\n", "Fahrenheit", "Celsius");
    printf("%10s %10s\n", "==========", "=======");
    for (int fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%10d %10.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
