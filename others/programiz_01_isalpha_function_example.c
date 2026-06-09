#include <stdio.h>
#include <ctype.h>

int main(void) {
    char c;

    c = 'Q';
    printf("Result when uppercase alphabet is passed: %d\n", isalpha(c));

    c = 'q';
    printf("Result when lowercase alphabet is passed: %d\n", isalpha(c));

    c = '+';
    printf("Result when non-alphabetic character is passed: %d\n", isalpha(c));
    return 0;
}
