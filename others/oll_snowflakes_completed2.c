#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <math.h>

#define MAX_SNOWFLAKES interior

#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 24

// Snowflake structure
typedef struct {
    int x;
    int y;
    int speed;
    char character;
    int active;  // Whether the snowflake is currently falling
} Snowflake;

// Function to get terminal size
void get_terminal_size(int *width, int *height) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    *width = w.ws_col;
    *height = w.ws_row - 1;
}

void set_noncanonical_mode() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

void restore_terminal_mode() {
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);
}

void clear_screen() {
    printf("\033[2J\033[H");
}

// Calculate number of active snowflakes based on temperature
int calculate_active_snowflakes(float temperature, int max_snowflakes) {
    // More snow when temperature is below freezing
    // Temperature range: -20°C to 40°C
    if (temperature <= -7.0) {
        // Max snow below -7°C
        return max_snowflakes;
    } else if (temperature >= 7.0) {
        // Minimal snow above 7°C
        return max_snowflakes / 10;  // 10% of max
    } else {
        // Linear interpolation between -7°C and 7°C
        float ratio = (7.0 - temperature) / 14.0;  // 14 is the range from -7 to 7
        return (int)(max_snowflakes * ratio);
    }
}

// Initialize snowflakes
void init_snowflakes(Snowflake snowflakes[], int count, int width, int height, float temperature) {
    int active_count = calculate_active_snowflakes(temperature, count);
    
    for (int i = 0; i < count; i++) {
        snowflakes[i].x = rand() % width;
        snowflakes[i].y = rand() % height;
        snowflakes[i].speed = 1 + rand() % 3;
        // Random snowflake characters
        switch (rand() % 4) {
            case 0: snowflakes[i].character = '*'; break;
            case 1: snowflakes[i].character = '+'; break;
            case 2: snowflakes[i].character = '.'; break;
            case 3: snowflakes[i].character = 'o'; break;
        }
        // Only activate some snowflakes based on temperature
        snowflakes[i].active = (i < active_count) ? 1 : 0;
    }
}

// Update snowflakes - animation happens automatically
void update_snowflakes(Snowflake snowflakes[], int count, int width, int height, float temperature) {
    // Update active count based on current temperature
    int active_count = calculate_active_snowflakes(temperature, count);
    
    // Update active status for each snowflake
    for (int i = 0; i < count; i++) {
        if (i < active_count) {
            // Activate snowflake if it should be active
            if (!snowflakes[i].active) {
                snowflakes[i].active = 1;
                snowflakes[i].x = rand() % width;
                snowflakes[i].y = 0;
            }
            
            // Move active snowflake
            snowflakes[i].y += snowflakes[i].speed;
            
            // Add slight horizontal drift
            if (rand() % 10 < 2) {
                if (rand() % 2) snowflakes[i].x++;
                else snowflakes[i].x--;
            }
            
            // Reset if it falls off the bottom
            if (snowflakes[i].y >= height) {
                snowflakes[i].y = 0;
                snowflakes[i].x = rand() % width;
            }
            
            // Handle horizontal boundaries
            if (snowflakes[i].x >= width) snowflakes[i].x = 0;
            if (snowflakes[i].x < 0) snowflakes[i].x = width - 1;
        } else {
            // Deactivate snowflake if it shouldn't be active
            snowflakes[i].active = 0;
        }
    }
}

// Draw the thermostat interface
void draw_interface(float temperature, int width) {
    // Draw top border
    printf("\033[0;37m");
    for (int i = 0; i < width; i++) printf("═");
    printf("\n");
    
    // Draw title
    printf("\033[1;36m");
    printf("  THERMOSTAT SIMULATION WITH SNOW ANIMATION\n");
    
    // Draw temperature
    printf("\033[0;33m");
    printf("  Current Temperature: ");
    
    // Color code based on temperature
    if (temperature < 0) printf("\033[0;34m");       // Blue for freezing
    else if (temperature < 15) printf("\033[0;32m"); // Green for cool
    else printf("\033[0;31m");                      // Red for warm
    
    printf("%.1f°C", temperature);
    
    // Draw thermostat visualization
    printf("\033[0;37m\n  Thermostat: [");
    
    // Map temperature -20°C to 40°C to bar width
    float temp_range = 60.0;  // -20 to 40 = 60 degrees
    float normalized_temp = temperature + 20.0;  // Shift so -20 becomes 0
    int bar_length = (int)((width - 30) * (normalized_temp / temp_range));
    if (bar_length < 0) bar_length = 0;
    if (bar_length > width - 30) bar_length = width - 30;
    
    // Draw colored bar
    for (int i = 0; i < bar_length; i++) {
        float pos_temp = (i * temp_range / (width - 30)) - 20.0;
        if (pos_temp < 0) printf("\033[0;34m");       // Blue for freezing
        else if (pos_temp < 10) printf("\033[0;32m"); // Green for moderate
        else printf("\033[0;31m");                   // Red for warm
        printf("█");
    }
    
    printf("\033[0;37m");
    for (int i = bar_length; i < width - 30; i++) printf(" ");
    printf("]\n");
    
    // Draw snow condition indicator
    printf("\033[0;36m");
    if (temperature <= -7.0) {
        printf("  Condition: ❄️ Heavy Snowstorm ❄️\n");
    } else if (temperature < 0) {
        printf("  Condition: ❄️ Snowing ❄️\n");
    } else if (temperature < 7.0) {
        printf("  Condition: 🌧️ Light Snow/Rain 🌧️\n");
    } else {
        printf("  Condition: ☀️ Sunny/Clear ☀️\n");
    }
    
    // Draw snow intensity
    printf("\033[0;35m");
    int snow_intensity = (int)(100.0 * (7.0 - temperature) / 14.0);
    if (snow_intensity < 0) snow_intensity = 0;
    if (snow_intensity > 100) snow_intensity = 100;
    printf("  Snow Intensity: %d%%\n", snow_intensity);
    
    // Draw controls
    printf("\033[1;37m");
    printf("  Controls: '+' to increase temperature | '-' to decrease | 'q' to quit\n");
    
    // Draw bottom border
    printf("\033[0;37m");
    for (int i = 0; i < width; i++) printf("═");
    printf("\033[0m\n");
}

// Draw snowflakes
void draw_snowflakes(Snowflake snowflakes[], int count, int width, int height) {
    // Move cursor to start of drawing area
    printf("\033[%d;0H", 9);  // Start after the interface
    
    // Create a buffer for the snow scene
    char buffer[height][width];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            buffer[y][x] = ' ';
        }
    }
    
    // Add active snowflakes to buffer
    int active_count = 0;
    for (int i = 0; i < count; i++) {
        if (snowflakes[i].active) {
            active_count++;
            if (snowflakes[i].x >= 0 && snowflakes[i].x < width && 
                snowflakes[i].y >= 0 && snowflakes[i].y < height) {
                buffer[snowflakes[i].y][snowflakes[i].x] = snowflakes[i].character;
            }
        }
    }
    
    // Draw the buffer
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (buffer[y][x] != ' ') {
                printf("\033[1;37m%c\033[0m", buffer[y][x]);
            } else {
                printf(" ");
            }
        }
        if (y < height - 1) printf("\n");
    }
    
    // Show active snowflake count in corner (optional)
    printf("\033[%d;%dH", height - 1, width - 15);
    printf("\033[0;36mSnowflakes: %d\033[0m", active_count);
}

int main() {
    // Initialize
    srand(time(NULL));
    
    // Get terminal size
    int width, height;
    get_terminal_size(&width, &height);
    
    // Adjust height for snow area
    int snow_height = height - 9;  // Reserve space for interface
    if (snow_height < 5) snow_height = 5;
    
    // Calculate max snowflakes based on terminal size
    int max_snowflakes = (width * snow_height) / 4;
    if (max_snowflakes > 500) max_snowflakes = 500;
    if (max_snowflakes < 50) max_snowflakes = 50;
    
    // Initialize snowflakes array
    Snowflake snowflakes[max_snowflakes];
    
    // Set terminal mode
    set_noncanonical_mode();
    
    // Main variables
    float temperature = 0.0;  // Starting at 0°C
    char input;
    int running = 1;
    
    // Initial snowflake initialization
    init_snowflakes(snowflakes, max_snowflakes, width, snow_height, temperature);
    
    // Main loop
    while (running) {
        clear_screen();
        
        // Draw interface
        draw_interface(temperature, width);
        
        // Update and draw snowflakes (animation is automatic)
        update_snowflakes(snowflakes, max_snowflakes, width, snow_height, temperature);
        draw_snowflakes(snowflakes, max_snowflakes, width, snow_height);
        
        // Move cursor out of the way
        printf("\033[%d;0H", height);
        
        // Handle input
        if (read(0, &input, 1) > 0) {
            switch (input) {
                case '+':
                case '=':
                    temperature += 1.0;
                    if (temperature > 40.0) temperature = 40.0;
                    break;
                case '-':
                case '_':
                    temperature -= 1.0;
                    if (temperature < -20.0) temperature = -20.0;
                    break;
                case 'q':
                case 'Q':
                    running = 0;
                    break;
            }
        }
        
        // Small delay for animation
        usleep(80000);  // 80ms for smooth animation
    }
    
    // Restore terminal mode
    restore_terminal_mode();
    
    // Clear screen and exit
    clear_screen();
    printf("\033[0;32mThank you for using the Thermostat Simulation!\033[0m\n");
    
    return 0;
}
