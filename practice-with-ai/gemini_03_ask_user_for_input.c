#include <stdio.h>

int main(void) {
    char password[8];
    char repassword[8];
    char username[20];

    printf("Enter password: ");
    scanf("%s", password); // without width limit, if more than 7 characters, weird behaviour occur

    printf("Re-enter password: ");
    scanf("%7s", repassword); // with width limit, safe if characters more than 7

    printf("Enter username (no spaces): ");
    scanf("%19s", username);

    printf("Your password is: %s\n", password);
    printf("Your repassword is %s\n", repassword);
    printf("Username set to: %s\n", username);

    return 0;
}
