#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random;

    // Sed the generator using the current time
    srand(time(NULL));

    // 0 to N-1
    random = rand() % 10;
    printf("Random: %d\n", random);

    // 1 - N
    random = (rand() % 10) + 1;
    printf("Random: %d\n", random);

    // Min to Max
    random = (rand() % (20 - 10 + 1)) + 10;
    printf("Random %d\n", random);

    return 0;
}
