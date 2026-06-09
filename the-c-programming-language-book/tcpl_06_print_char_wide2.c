#include <stdio.h>

int main(void) {
    char star = '*';

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != 1 && j != 1) {
                printf("%2c", star);
            }
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
