#include <dirent.h>
#include <stdio.h>

int main(void) {
    DIR *dir = opendir(".");

    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
