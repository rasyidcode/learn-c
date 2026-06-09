#include <stdio.h>

int main(void) {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int numbers_size = sizeof(numbers) / sizeof(numbers[0]);

  printf("Numbers: ");
  for (int i = 0; i < numbers_size; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  printf("Numbers2: ");
  for (int i = 0; i <= 100; i += 10) {
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}
