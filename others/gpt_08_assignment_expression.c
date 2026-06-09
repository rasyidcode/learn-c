#include <stdio.h>

int main(void) {
    int a, b;
    int c, d, e;
    int f = 1;
    int g;
    int h;
    int i = 2;
    int j = 3;
    int k = 10;
    int l = 20;

    b = a = 10;
    e = d = c = 5;
    g = (f = 7) + 3;
    h = 15;

    printf("a=%d b=%d\n", a, b);
    printf("c=%d d=%d e=%d\n", c, d, e);
    printf("f=%d g=%d\n", f, g);
    printf("g=%d\n", (g = 69));
    printf("g=%d\n", g);
    printf("i=%d\n", (i = j));
    printf("i=%d j=%d\n", i, j);

    printf("before if -> k=%d\n", k);
    if (k = 0)
        printf("k is true\n");
    else
        printf("k is false\n"); 
    printf("after if -> k=%d\n", k);

    printf("before if -> l=%d\n", l);
    if (l = 19)
        printf("l is true\n");
    else
        printf("l is false\n");
    printf("after if -> l=%d\n", l);

    printf("before if -> a=%d f=%d\n", a, f);
    if (a = f)
        printf("a=f is true\n");
    else
        printf("a=f is false\n");
    printf("after if -> a=%d f=%d\n", a, f);

    return 0;
}
