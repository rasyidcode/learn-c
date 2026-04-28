#include <stdio.h>

void times10Array(int arr[], int size);

int main() {
  int nums[] = {9, 4, 2, 3, 5};
  int nums_size = sizeof(nums) / sizeof(nums[0]);

  printf("Before: ");
  for (int i = 0; i < nums_size; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  times10Array(nums, nums_size);

  printf("After: ");
  for (int i = 0; i < nums_size; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}

void times10Array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = arr[i] * 10;
  }
}
