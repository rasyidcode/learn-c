#include <stdio.h>

int main(int argc, char **args) {
    int i;

    printf("Total number of args: %d\n", argc);

    // int length = sizeof(args) / sizeof(args[0]);
    for (i = 0; i < argc; i++) {
        printf("Arg #%d => %s\n", i+1, args[i]);
    }

    return 0;
}
