#include <ctype.h>
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

//static int is_numeric2(const char s[]) {
//    while (s)
//}

int main(void) {
    char *c = "helloworld";
    char *c2 = "11111";
    char c3[] = "dota 2 beta";

    printf("c is numeric? %d\n", is_numeric(c));
    printf("c2 is numeric? %d\n", is_numeric(c2));

    printf("is c digit? %d\n", isdigit(*c));
    printf("is c2 digit? %d\n", isdigit(*c2));

    while (*c) {
        printf("%c\t", *c);
        c++;
    }
    printf("\n");

    while (*c3) {
        printf("%c ", *c);
        *c3 += 1;
    }
    printf("\n");

    return 0;
}
