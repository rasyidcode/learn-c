#include <stdio.h>
#include <termios.h>

#define MAX_STARS 100

typedef struct {
    int x, y;
} Star;

void enable_raw_mode(void) {
    struct termios raw;
}

int main(void) {
    Star stars[MAX_STARS];
    int num_stars = 60; // number of stars on screen
    int term_cols, term_rows;
    int i;



    return 0;
}
