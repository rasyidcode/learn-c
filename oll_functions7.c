#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int calculate(int x, int y, int (*op)(int, int));

int main() {
  int a = 10, b = 3;
  int (*calculate)(int, int);

  calculate = add;
  int sum = calculate(a, b);
  printf("add(%d, %d) = %d\n", a, b, sum);

  calculate = subtract;
  int diff = calculate(a, b);
  printf("diff(%d, %d) = %d\n", a, b, diff);

  return 0;
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
