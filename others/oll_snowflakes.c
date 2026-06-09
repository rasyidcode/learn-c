#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

#define MAX_SNOWFLAKES  200
#define TERMINAL_WIDTH  80
#define TERMINAL_HEIGHT 24

// snowflake structure
typedef struct {
    int x;
    int y;
    int speed;
    char character;
} Snowflake;

void get_terminal_size(int *width, int *height);
void init_snowflakes(Snowflake snowflakes[], int count, int width, int height);
void set_noncanonical_mode();
void restore_terminal_mode();
void clear_screen();
void update_snowflakes(Snowflake snowflakes[], int count, int width, int height, float temperature);
void draw_interface(float temperature, int width);
void draw_snowflakes(Snowflake snowflakes[], int count, int width, int height, float temperature);

int main(void) {
    srand(time(NULL));

    // get terminal size
    int width, height;
    get_terminal_size(&width, &height);

    // adjust height for snow area
    int snow_height = height - 7; // reserve space for interface
    if (snow_height < 5) snow_height = 5;

    // initialize snowflakes
    Snowflake snowflakes[MAX_SNOWFLAKES];
    init_snowflakes(snowflakes, MAX_SNOWFLAKES, width, snow_height);

    // set terminal mode
    set_noncanonical_mode();

    // main variable
    float temperature = 50.0; // starting temperature
    char input;
    int running = 1;

    // main loop
    while (running) {
        clear_screen();

        // draw interface
        draw_interface(temperature, width);

        // update and draw snowflakes
        update_snowflakes(snowflakes, MAX_SNOWFLAKES, width, snow_height, temperature);
        draw_snowflakes(snowflakes, MAX_SNOWFLAKES, width, snow_height, temperature);

        // move cursor out of the way
        printf("\033[%d;0H", height);

        // handle input
        if (read(0, &input, 1) > 0) {
            switch (input) {
                case '+':
                case '=':
                    temperature += 5.0;
                    if (temperature > 100.0) temperature = 100.0;
                    break;
                case '-':
                case '_':
                    temperature -= 5.0;
                    if (temperature < 0.0) temperature = 0.0;
                    break;
                case 'q':
                case 'Q':
                    running = 0;
                    break;
            }
        }

        // small delay for animation
        usleep(100000); // 100ms
    }

    // restore terminal mode
    restore_terminal_mode();

    // clear screen and exit
    clear_screen();
    printf("\033[0;32mThank youu for using the Thermostat Simulation!\033[0m\n");

    return 0;
}

// function to get terminal size
void get_terminal_size(int *width, int *height) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    *width = w.ws_col;
    *height = w.ws_row - 1; // reserve one line for controls
}

// init snowflakes
void init_snowflakes(Snowflake snowflakes[], int count, int width, int height) {
    for (int i = 0; i < count; i++) {
        snowflakes[i].x = rand() % width;
        snowflakes[i].y = rand() % height;
        snowflakes[i].speed = 1 + rand() % 3;
        // random snowflakes character
        switch (rand() % 4) {
            case 0: snowflakes[i].character = '*'; break;
            case 1: snowflakes[i].character = '+'; break;
            case 2: snowflakes[i].character = '.'; break;
            case 3: snowflakes[i].character = 'o'; break;
        }
    }
}

// function to set terminal to non-cannonical mode
void set_noncanonical_mode() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

// function to restore terminal to canonical mode
void restore_terminal_mode() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

// function to clear the screen
void clear_screen() {
    printf("\033[2J\033[H");
}

// update snowflakes based on temperature
void update_snowflakes(Snowflake snowflakes[], int count, int width, int height, float temperature) {
    // calculate active snowflakes based on temperature
    // more temperature = more snow
    int active_count = (int)(count * (temperature / 100.0));
    if (active_count > count) active_count = count;

    for (int i = 0; i < active_count; i++) {
        // move snowflake down based on temperature (higher temp = faster)
        snowflakes[i].y += (int)(snowflakes[i].speed * (temperature / 50.0));

        // add some horizontal movement
        if (rand() % 10 < 3) {
            if (rand() % 2) snowflakes[i].x++;
            else snowflakes[i].x--;
        }

        // wrap around if out bounds
        if (snowflakes[i].y >= height) {
            snowflakes[i].y = 0;
            snowflakes[i].x = rand() % width;
        }

        if (snowflakes[i].x >= width) snowflakes[i].x = 0;
        if (snowflakes[i].x < 0) snowflakes[i].x = width - 1;
    }
}

// draw the thermostat interface
void draw_interface(float temperature, int width) {
    // draw top border
    printf("\033[0;37m"); // white color
    for (int i = 0; i < width; i++) printf("=");
    printf("\n");

    // draw title
    printf("\033[1;36m]"); // cyan color
    printf("  THERMOSTAT SIMULATION WITH SNOW ANIMATION\n"); 

    // draw temperature
    printf("\033[0;33m"); // yellow color
    printf("  Current Temperature: ");

    // color code based on temperature
    if (temperature < 30) printf("\033[0;34m"); // blue for cold
    else if (temperature < 70) printf("\033[0;32m"); // green for moderate
    else printf("\033[0;31m"); // red for hot

    printf("%.1f°C", temperature);

    // draw thermostat visualization
    printf("\033[0;37m\n  Thermostat: [");

    int bar_length = (int)((width - 30) * (temperature / 100.0));
    for (int i = 0; i < bar_length; i++) {
        if (i < bar_length / 3) printf("\033[0;34m]"); // blue
        else if (i < 2 * bar_length / 3) printf("\033[0;32m"); // green
        else printf("\033[0;31m"); // red
        printf("█");
    }

    printf("\033[0;37m");
    for (int i = bar_length; i < width - 30; i++) printf(" ");
    printf("]\n");

    // draw controls
    printf("\033[1;37m");
    printf("  Controls: '+' to increase temperature | '-' to decrease | 'q' to quit\n");

    // draw snow info
    printf("\033[0;36m");
    printf("  Snow intensity: %.0f%% | Snow speed: %.0f%%\n",
            (temperature / 100.0) * 100,
            (temperature / 50.0) * 100);
    
    // draw bottom border
    printf("\033[0;37m");
    for (int i = 0; i < width; i++) printf("=");
    printf("\033[0m;\n"); // reset color
}

// draw snowflakes
void draw_snowflakes(Snowflake snowflakes[], int count, int width, int height, float temperature) {
    // calculate active snowflakes based on temperature
    int active_count = (int)(count * (temperature / 100.0));
    if (active_count > count) active_count = count;

    // move cursor to start of drawing area
    printf("\033[%d;0H", 7); // start after the interface

    // create a buffer for the snow scene
    char buffer[height][width];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            buffer[y][x] = ' ';
        }
    }

    // Add snowflakes to buffer
    for (int i = 0; i < active_count; i++) {
        if (snowflakes[i].x >= 0 && snowflakes[i].x < width &&
            snowflakes[i].y >= 0 && snowflakes[i].y < height) {
            buffer[snowflakes[i].y][snowflakes[i].x] = snowflakes[i].character;
        }
    }

    // draw the buffer
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // make snowflakes white
            if (buffer[y][x] != ' ') {
                printf("\033[1;37m%c\033[0m", buffer[y][x]);
            } else {
                printf(" ");
            }
        }
        if (y < height - 1) printf("\n");
    }
}
