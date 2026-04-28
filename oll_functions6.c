#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int calculate(int x, int y, int (*op)(int, int));

int main() {
  int a = 10, b = 3;

  int sum = calculate(a, b, add); // pass function `add`
  int diff = calculate(a, b, subtract); // pass function `subtract`

  printf("add(%d, %d) = %d\n", a, b, sum);
  printf("diff(%d, %d) = %d\n", a, b, diff);

  return 0;
}

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

int calculate(int x, int y, int (*op)(int, int)) {
  return op(x, y); // call the function pointed to by `op` 
}

