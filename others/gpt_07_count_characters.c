#include <stdio.h>

int main(void) {
    int c;
    int nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
    }

    printf("Number of characters is %d\n", nc);

    return 0;
}
