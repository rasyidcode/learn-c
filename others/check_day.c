#include <stdio.h>
#include <time.h>

int is_weekend() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    return tm->tm_wday == 0 || tm->tm_wday == 6;
}

int main(void) {
    printf("Is weekend? %d\n", is_weekend());

    return 0;
}
