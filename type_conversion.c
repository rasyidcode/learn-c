#include <stdio.h>

int main() {
  int x = 5;
  int y = 2;
  int sum = 5 / 2;

  printf("%d\n", sum);

  // Implicit Conversion
  float myFloat = 9;
  printf("%f\n", myFloat);

  int myInt = 9.9;
  printf("%d\n", myInt);

  float sum2 = 5 / 2;
  printf("%f\n", sum2);

  float sum4 = 5.0 / 2.0;
  printf("%f\n", sum4);

  // Explicit Conversion
  float sum3 = (float)5 / 2;
  printf("%f\n", sum3);

  float sum5 = (float)x / y;
  printf("%.1f\n", sum4);

  return 0;
}
