#include <ctype.h>
#include <dirent.h>
#include <stdio.h>

static int is_numeric(const char *s) {
    while (*s) {
        if (!isdigit(*s)) {
            return 0;
        }
        s++;
    }

    return 1;
}

int main(void) {
    DIR *proc = opendir("/proc");

    if (!proc) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;

    while ((entry = readdir(proc)) != NULL) {
        
    }

    return 0;
}
