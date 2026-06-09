#include <stdio.h>

void showMenu() {
    printf("\n=== Smart Access System ===\n");
    printf("1. Add Guest\n");
    printf("2. Show Guests\n");
    printf("0. Exit\n");
}

int main() {
    int choice;

    while(1) {
        showMenu();
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 0)
    }

    return 0;
}

