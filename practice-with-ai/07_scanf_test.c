#include <stdio.h>

int main(void) {
    int number;
    int status;

    printf("Enter a number: ");
    status = scanf("%d", &number);

    printf("You entered: %d\n", number);
    printf("scanf returned: %d\n", status);

    return 0;
}
