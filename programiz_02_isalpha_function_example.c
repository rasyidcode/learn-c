#include <stdio.h>
#include <ctype.h>

int main(void) {
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    if (isalpha(c) == 0) {
        printf("%c is not alphabet\n", c);
    } else {
        printf("%c is alphabet\n", c);
    }

    return 0;
}
