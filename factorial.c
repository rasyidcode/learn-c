#include <stdio.h>

void factorial(int n) {
  int result;

  // 5! = 4 x 3 x 2 x 1 = 24
  // 6! = 5 x 4 x 3 x 2 x 1 = 120

  /*
  result = 1;
  for (int i = 1; i < n; i++) {
    result = result * i;  
  }
  */

  result = 1;
  for (int i = n - 1; i > 1; i--) {
    result = result * i;
  }

  /*
    result = 4
    i = 4
    4 > 1

    result = 4 * (4 - 1)
    result = 4 * 3
    result = 12
    i = 3
    3 > 1

    result = 12 * (3 - 1)
    result = 12 * 2
    result = 24
    i = 2
    2 > 1

    result = 24 * (2 - 1)
    result = 24 * 1
    i = 1
    1 > 1

  */

  printf("%d! is %d\n", n, result);
}

int main() {
  factorial(5);  
  factorial(6);
  factorial(7);
  factorial(8);

  return 0;
}
