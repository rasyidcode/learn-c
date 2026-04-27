#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(void) {
    struct termios oldt, newt;
    char password[50];
    char show;

    // Get current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable echo
    newt.c_lflag &= ~(ECHO);

    // Apply new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    printf("Enter password: ");
    scanf("%s", password);

    // Restore old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    printf("\nPassword entered!\n");

    printf("\nShow password? (y/N)");
    scanf(" %c", &show);

    if (show == 'y') {
        printf("\nThe password is: %s\n", password);
    }

    return 0;
}
