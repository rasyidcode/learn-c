#include <stdio.h>
#include <string.h>

// AI-Assisted: Codex CLI
int main(void) {
    char password[8];
    char repassword[8];
    char username[20];

    printf("Enter password: ");
    if (fgets(password, sizeof password, stdin)) {
        password[strcspn(password, "\n")] = '\0';
    }
    
    printf("Enter repassword: ");
    if (fgets(repassword, sizeof repassword, stdin)) {
        repassword[strcspn(repassword, "\n")] = '\0';
    }

    printf("Enter username: ");
    if (fgets(username, sizeof username, stdin)) {
        username[strcspn(username, "\n")] = '\0';
    }

    printf("Your password is: %s\n", password);
    printf("Re-enter password is: %s\n", repassword);
    printf("Username set to: %s\n", username);

    return 0;
}
