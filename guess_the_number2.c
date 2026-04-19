#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to play one round
int playGame(int maxNumber, int maxAttempts) {
    int number, guess, attempts = 0;

    // Generate random number between 1-100
    number = rand() % maxNumber + 1;

    printf("\nI picked a number between 1 and %d\n", maxNumber);

    while (attempts < maxAttempts) {
        printf("Attempts left: %d\n", maxAttempts - attempts);
        printf("\nEnter your guess: ");
        scanf("%d", &guess);

        attempts++;
        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("\n🎉 Correct! You won in %d attempts.\n", attempts);
            return maxAttempts - attempts + 1; // score
        }
    }

    printf("💀 You lost! The number was %d\n", number);
    return 0;
}

int main() {
    int choice, score = 0;
    char playAgain;

    // Seed random number generator
    srand(time(0));

    printf("🎮 Welcome to Advanced Guessing Game!\n");

    do {
        printf("\nChoose Difficulty:\n");
        printf("1. Easy (1-50, 10 attempts)\n");
        printf("2. Medium (1-100, 7 attempts)\n");
        printf("3. Hard (1-200, 5 attempts)\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                score += playGame(50, 10);
                break;
            case 2:
                score += playGame(100, 7);
                break;
            case 3:
                score += playGame(200, 5);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printf("🏆Total score: %d\n", score);

        printf("\nPlay again (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("👋 Thanks for playing! Final Score: %d\n", score);

    return 0;
}
