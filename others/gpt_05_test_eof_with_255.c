#include <stdio.h>

int main(void) {
    char c;

    c = 255;

    if (c == EOF) {
        printf("Mistaken as EOF!\n");
    } else {
        printf("Normal character\n");
    }

    return 0;
}
