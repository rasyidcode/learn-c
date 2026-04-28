#include <stdio.h>

int maxNumber(int arr[], int arrSize);

int main() {
  int temps[] = {23, 30, 28, 27, 35, 23, 31};
  int tempsSize = sizeof(temps) / sizeof(temps[0]);

  printf("The max number from (");
  for (int i = 0; i < tempsSize; i++) {
    if (i >= tempsSize - 1) {
      printf("%d", temps[i]);
    } else {
      printf("%d, ", temps[i]);
    }
  }
  printf(") is %d\n", maxNumber(temps, tempsSize));

  return 0;
}

int maxNumber(int arr[], int arrSize) {
  int result = arr[0];

  for (int i = 0; i < arrSize; i++) {
    if (result < arr[i]) {
      result = arr[i];
    }
  }

  return result;
}
