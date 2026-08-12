#include <stdio.h>

int main(void) {
    char str[] = "Hello";
    printf("without null terminator -> %s\n", str);

    char str2[6] = {'H', 'e', 'l', 'l', 'o'};
    printf("with null terminator -> %s\n", str2);

    return 0;
}
