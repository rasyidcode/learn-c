#include <stdio.h>

int main(void) {
    // Initializing with a character literal
    unsigned char letter = 'A';

    // Initializing with a raw integer numeric value
    unsigned char number = 200;

    // %c prints the character
    // %hhu prints the raw integer numeric value
    printf("As character: %c\n", letter);
    printf("As number: %hhu\n", letter);
    printf("Stored number: %hhu\n", number);
    printf("Stored char: %c\n", number);

    return 0;
}
