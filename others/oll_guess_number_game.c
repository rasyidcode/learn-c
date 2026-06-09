#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int secretNumber;
  int playerGuess;
  int attempts;

  srand(time(NULL));

  secretNumber = rand() % 100 + 1;
  attempts = 0;
  
  printf("Welcome to Guess The Number Game\n");
  printf("I'm thinking of a number between 1 and 100\n");

  while(playerGuess != secretNumber) {
    printf("Your guess: ");
    scanf("%d", &playerGuess);

    if (playerGuess > secretNumber) {
      printf("Too high! Try again.\n");
    } else if (playerGuess < secretNumber) {
      printf("Too low! Try again.\n");
    }

    attempts++;
  }

  printf("You guessed it with %d attempts\n", attempts);

  return 0;
}

