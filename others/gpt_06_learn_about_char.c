#include <stdio.h>

int main(void) {
    char c;

    c = 120;

    if (c == EOF) {
        printf("Mistaken as EOF!\n");
    } else {
        printf("Normal character\n");
    }

    printf("ASCII value of 120 is %c\n", c);
    printf("EOF value: %d\n", EOF);

    return 0;
}
