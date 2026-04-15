#include <stdio.h>

int main() {
    int number = 10; // normal variable
    int number2 = 30;

    int *ptr;        // pointer variable
    int *ptr2;
     
    ptr = &number;   // store address of number in pointer
    ptr = &number2;

    printf("Before swap: \n");
    printf("number: %d\n", number);
    printf("number2: %d\n", number2);
     
    int tmp = number;

    ptr = ptr2;
    ptr2 = tmp;

    printf("\nAfter swap: \n");
    printf("number: %d\n", number);
    printf("number2: %d\n", number2);
 
    return 0;
}
