#include <stdio.h>

int main() {
    int myAge = 29;

    printf("%d\n", myAge);
    printf("%p\n", &myAge);

    int *p = &myAge;

    *p = 12;

    printf("%d\n", myAge);
    printf("%d\n", *p);

	return 0;
}
