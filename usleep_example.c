#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Waiting for 5s...\n");

    usleep(5 * 60 * 10000);
    
    printf("Done.\n");

    return 0;
}
