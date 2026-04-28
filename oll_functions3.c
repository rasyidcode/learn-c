#include <stdio.h>

int doubleArray(int arr[], int size);

int main() {
  int numbers[] = {1, 2, 3, 4, 5};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  printf("Before: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  doubleArray(numbers, size);

  printf("After: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  return 0;
}

int doubleArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] *= 2; // Doubles each element
  }
}
