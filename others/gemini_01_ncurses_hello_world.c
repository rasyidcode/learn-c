#include <ncurses.h>

int main(void) {
    // init ncurses
    initscr();

    // print a string to the default window (stdscr)
    printw("Hello, ncurses! Press any key to exit...");

    // refresh the screen to show the changes
    refresh();

    // wait for user input before exiting
    getch();

    // end ncurses mode
    endwin();

    return 0;
}
