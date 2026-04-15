#include <stdio.h>

int main() {
    int number = 10; // normal variable
    int *ptr;        // pointer variable
     
    ptr = &number;   // store address of number in pointer
     
    // print value and address
    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", &number);

    // using pointer
    printf("Pointer ptr stores address: %p\n", ptr);
    printf("Value at that address (*ptr): %d\n", *ptr);

    // Modify value using pointer
    *ptr = 20;

    printf("\nAfter modifying using pointer:\n");
    printf("Value of number: %d\n", number);
    printf("Value from pointer (*ptr): %d\n", *ptr);
 
    return 0;
}
