// source: https://www.w3schools.com/c/c_arrays_size.php

#include <stdio.h>

int main() {
  int scores[] = {85, 75, 100, 90, 80};
  int scores_size = sizeof(scores) / sizeof(scores[0]);
  float daily_temperatures[] = {30.5, 31.2, 29.8, 30.0, 32.1, 31.7, 30.9};
  int daily_temperatures_size = sizeof(daily_temperatures) / sizeof(daily_temperatures[0]);

  printf("Total bytes in array: %zu\n", sizeof(scores));
  printf("Total items in array: %d\n", scores_size);
  printf("\n");
  printf("Total bytes of daily_temperatures: %zu\n", sizeof(daily_temperatures));
  printf("Total items of daily_temperatures: %d\n", daily_temperatures_size);
  printf("\n");

  return 0;
}
