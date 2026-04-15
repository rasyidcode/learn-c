#include <stdio.h>

int main() {
    int a = 5, b = 10;
    int *ptr;

    ptr = &a;
    printf("Pointer points to a: %d\n", *ptr);

    ptr = &b;
    printf("Pointer now points to b: %d\n", *ptr);
 
    return 0;
}
