#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Sed the generator using the current time
    srand(time(NULL));

    printf("Random: %d\n", rand());
    return 0;
}
