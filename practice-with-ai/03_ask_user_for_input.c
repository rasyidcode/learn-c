#include <stdio.h>

// AI-Assisted: Gemini Web Search
int main(void) {
    char password[8];
    char repassword[8];
    char username[20];

    printf("Enter password: ");
    scanf("%s", password); // without width limit, if more than 7 characters, weird behaviour occur

    printf("Re-enter password: ");
    scanf("%7s", repassword); // with width limit, if more than 7 characters is safe, but it does not safe for the next scanf, because it only takes 7 characters and the remaining carahcters stays in buffer, then the next scanf takes it

    printf("Enter username (no spaces): ");
    scanf("%19s", username);

    printf("Your password is: %s\n", password);
    printf("Your repassword is %s\n", repassword);
    printf("Username set to: %s\n", username);

    return 0;
}
