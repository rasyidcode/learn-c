#include <stdio.h>

void scanf_like(int *ptr) {
    *ptr = 25; // writing directly into variable
}

int main() {
    int age = 30;

    printf("%d\n", age);
    printf("%p\n", &age);

    printf("before scanf_like: %d\n", age);

    scanf_like(&age);

    printf("after scanf_like: %d\n", age);

    printf("%d\n", age);

    int number;
    printf("Input a number: ");
    scanf("%d", &number);

    printf("the value of number is: %d\n", number);

    return 0;
}
