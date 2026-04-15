#include <stdio.h>
#include <string.h>

int main() {
    char username[20];
    int pin;

    printf("Enter username: ");
    scanf("%s", username); // no & (pointer) needed

    printf("Enter PIN: "); // pointer needed
    scanf("%d", &pin);

    //printf("\nYou entered:\n");
    //printf("Username: %s\n", username);
    //printf("PIN: %d\n", pin);

    if (strcmp(username, "admin") == 0 && pin == 1234) {
        printf("Access Granted!\n");
    } else {
        printf("Access Denied!\n");
    }

    return 0;
}
