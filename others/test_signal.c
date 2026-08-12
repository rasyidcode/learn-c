#include <stdio.h>
#include <signal.h>

void handler(int sig) {
    printf("Received signal %d\n", sig);
}

int main(void) {
    signal(SIGINT, handler);

    while (1)
        ;

    return 0;
}
