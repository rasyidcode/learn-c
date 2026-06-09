#include <stdio.h>
#include <time.h>

int main() {
    time_t seconds;
    struct tm *curr_time;

    seconds = time(NULL);
    curr_time = localtime(&seconds);

    printf("Current Time -> %02d:%02d:%02d\n", curr_time->tm_hour, curr_time->tm_min, curr_time->tm_sec);

    return 0;
}
