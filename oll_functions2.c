#include <stdio.h>

int add(int a, int b);

int main() {
  int x = 5, y = 7;
  int sum = add(x, y);
  printf("Sum: %d\n", sum);
  return 0;
}

int add(int a, int b) {
  return a + b;
}
