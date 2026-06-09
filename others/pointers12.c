#include <stdio.h>

int main() {
    int pin;
    int *ptr = &pin;

    printf("Enter PIN: ");
    scanf("%d", ptr); // same as &pin

    printf("PIN: %d\n", pin);

    return 0;
}
