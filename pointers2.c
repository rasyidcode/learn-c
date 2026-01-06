#include <stdio.h>

int main() {
    int myAge = 30; // Variable decleration
    int* ptr = &myAge; // Pointer decleration

    // Reference: Output the memory address of myAge with the pointer
    printf("%p\n", ptr);

    // Dereference: Output the value of myAge with the pointer
    printf("%d\n", *ptr);
 
    return 0;
}
