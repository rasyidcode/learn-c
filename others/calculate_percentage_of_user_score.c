#include <stdio.h>

int main() {
  // set the maxium possible score in the game to 500
  int maxScore = 500;

  // The actual score of the user
  int userScore = 423;

  /* Calculate the percantage of the user's score in relation to the maxium
   * available score.
   * Convert userScore to float to make sure that the division is accurate */
  float percentage = (float)userScore / maxScore * 100.0;
  printf("User's percentage is %.2f\n", percentage);
}
