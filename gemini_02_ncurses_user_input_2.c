#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rand_color;
    int x = 10, y = 10;
    int ch;

    // init random
    srand(time(NULL));

    initscr();              // start ncurses mode
    
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    // start color functionality
    start_color();

    // init color
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);

    raw();                  // line buffering disabled
    keypad(stdscr, TRUE);   // enable arrow keys
    noecho();               // don't echo() while we do getch
    curs_set(0);            // hide cursor

    printw("Use arrow keys to move the '@'. Press 'q' to quit.");
    mvaddch(y, x, '@');
    refresh();

    while((ch = getch()) != 'q') {
        // clear previous position
        // mvaddch(y, x, ' ');

        rand_color = (rand() % 4) + 1;

        switch (ch) {
            case KEY_UP:
                if (y > 0) y--;
                break;
            case KEY_DOWN:
                if (y < LINES - 1) y++;
                break;
            case KEY_LEFT:
                if (x > 0) x--;
                break;
            case KEY_RIGHT:
                if (x < COLS - 1) x++;
                break;
        }

        attron(COLOR_PAIR(rand_color));
        mvaddch(y, x, '@');
        attroff(COLOR_PAIR(rand_color));
        refresh();
    }

    endwin();
    return 0;
}
