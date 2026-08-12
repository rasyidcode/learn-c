#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now = time(NULL);

    printf("%lld\n", (long long)now);

    return 0;
}
