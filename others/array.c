/**
 * source: https://www.w3schools.com/c/c_arrays.php
 */
#include <stdio.h>

int main() {
    // Define an array
    int numbers[] = {1, 3, 5, 7, 9};

    // Access the element of an array
    printf("%d\n", numbers[0]);

    // Change an array element
    numbers[1] = 69;
    printf("%d\n", numbers[1]);

    return 0;
}
