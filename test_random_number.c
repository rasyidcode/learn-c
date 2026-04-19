#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number;
    time_t seconds;
    time_t seconds2;

    srand(time(0));

    number = rand() % 10 + 1;

    seconds = time(NULL);

    printf("The random number is %d\n", number);
    printf("%ld\n", time(0));
    printf("Seconds since Jan 1, 1970: %ld\n", seconds);

    time(&seconds2);

    printf("Seconds since Jan 1, 1970: %ld\n", seconds2);

    return 0;
}
