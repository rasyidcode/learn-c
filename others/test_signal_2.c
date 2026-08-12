#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <signal.h>

int main(void) {
    if (kill(14121, SIGTERM) == -1) {
        perror("kill");
    }

    return 0;
}
