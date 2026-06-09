#include <stdio.h>

int main(void) {
    int nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    
    printf("\nNumber of characters is %d\n", nc);

    return 0;
}
