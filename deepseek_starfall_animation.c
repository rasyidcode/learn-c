/*
 * starfall.c - Terminal-based falling stars animation
 * Compile: gcc -o starfall starfall.c -lm
 * Run: ./starfall
 */

#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <poll.h>

// ANSI escape sequences
#define CLEAR_SCREEN     "\033[2J"
#define CURSOR_HOME      "\033[H"
#define HIDE_CURSOR      "\033[?25l"
#define SHOW_CURSOR      "\033[?25h"
#define CURSOR_POS(row,col) "\033[%d;%dH", (row), (col)

#define MAX_STARS 100
#define DEFAULT_WIDTH  80
#define DEFAULT_HEIGHT 24
#define FRAME_DELAY_US 50000  // 50 ms -> ~20 FPS

typedef struct {
    int x, y;
} Star;

static struct termios orig_termios;
static int terminal_modified = 0;

// Restore terminal settings on exit
void restore_terminal(void) {
    if (terminal_modified) {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
        printf(SHOW_CURSOR);
        printf(CLEAR_SCREEN);
        printf(CURSOR_HOME);
        fflush(stdout);
        terminal_modified = 0;
    }
}

// Signal handler for clean exit
void handle_sigint(int sig) {
    (void)sig;
    restore_terminal();
    exit(0);
}

// Enable raw mode: no echo, no line buffering, non-blocking read
void enable_raw_mode(void) {
    struct termios raw;

    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
        perror("tcgetattr");
        exit(1);
    }

    raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);   // disable echo and canonical mode
    raw.c_cc[VMIN] = 0;                // non-blocking read
    raw.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        perror("tcsetattr");
        exit(1);
    }

    terminal_modified = 1;
    atexit(restore_terminal);
    signal(SIGINT, handle_sigint);
    signal(SIGTERM, handle_sigint);
}

// Get current terminal dimensions
void get_terminal_size(int *cols, int *rows) {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
        // Fallback to environment variables or defaults
        char *env_cols = getenv("COLUMNS");
        char *env_rows = getenv("LINES");
        *cols = env_cols ? atoi(env_cols) : DEFAULT_WIDTH;
        *rows = env_rows ? atoi(env_rows) : DEFAULT_HEIGHT;
    } else {
        *cols = ws.ws_col;
        *rows = ws.ws_row;
    }
}

// Check if a key has been pressed (non-blocking)
int key_pressed(void) {
    struct pollfd fds = { .fd = STDIN_FILENO, .events = POLLIN };
    return poll(&fds, 1, 0) > 0;
}

// Read a single character (if available)
char read_key(void) {
    char c;
    if (read(STDIN_FILENO, &c, 1) == 1)
        return c;
    return 0;
}

int main(void) {
    Star stars[MAX_STARS];
    int num_stars = 60;  // number of stars on screen
    int term_cols, term_rows;
    int i;

    enable_raw_mode();
    printf(HIDE_CURSOR);
    fflush(stdout);

    srand(time(NULL));

    // Get initial terminal size
    get_terminal_size(&term_cols, &term_rows);

    // Initialize stars with random positions
    for (i = 0; i < num_stars; i++) {
        stars[i].x = rand() % term_cols;
        stars[i].y = rand() % term_rows;
    }

    // Main animation loop
    while (1) {
        // Clear screen and move cursor home
        printf(CLEAR_SCREEN);
        printf(CURSOR_HOME);
        
        // Update terminal size (handles window resize)
        get_terminal_size(&term_cols, &term_rows);

        // Update star positions
        for (i = 0; i < num_stars; i++) {
            stars[i].y += 1;
            // If star reached bottom or beyond, respawn at top
            if (stars[i].y >= term_rows) {
                stars[i].y = 0;
                stars[i].x = rand() % term_cols;
            }
            // Keep x within bounds if terminal width decreased
            if (stars[i].x >= term_cols)
                stars[i].x = term_cols - 1;
        }

        // Draw all stars
        for (i = 0; i < num_stars; i++) {
            // ANSI cursor positioning is 1-indexed
            printf(CURSOR_POS(stars[i].y + 1, stars[i].x + 1));
            putchar('*');
        }

        // Ensure output is displayed
        fflush(stdout);

        // Check for user input to exit
        if (key_pressed()) {
            char c = read_key();
            if (c == 'q' || c == 'Q' || c == 27) // 'q' or ESC
                break;
        }

        usleep(FRAME_DELAY_US);
    }

    // restore_terminal is called automatically via atexit
    return 0;
}
