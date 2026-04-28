#include <stdio.h>

unsigned long long factorial(int n);

int main() {
  printf("8! = %llu\n", factorial(8));
  return 0;
}

unsigned long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1; // base case
  }
  return n * factorial(n - 1); // recursive call
}
