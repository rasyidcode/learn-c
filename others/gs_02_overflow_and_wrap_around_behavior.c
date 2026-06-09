#include <stdio.h>

int main(void) {
    unsigned char val1 = 255;
    val1 = val1 + 1;
    printf("255 + 1 wraps to: %hhu\n", val1);

    unsigned char val2 = 0;
    val2 = val2 - 1;
    printf("0 - 1 wraps to: %hhu\n", val2);
    return 0;
}
