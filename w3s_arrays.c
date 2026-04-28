// source: https://www.w3schools.com/c/c_arrays.php

#include <stdio.h>

int main() {
  int fibo[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
  int prime[5];
  int primeSize = sizeof(prime) / sizeof(prime[0]);

  prime[0] = 2;
  prime[1] = 3;
  prime[2] = 5;
  prime[3] = 7;
  prime[4] = 11;

  printf("fibo[2] => %d\n", fibo[2]);

  fibo[2] = 69;

  printf("fibo[2] => %d\n", fibo[2]);

  printf("Prime number: ");
  for (int i = 0; i < primeSize; i++) {
    printf("%d ", prime[i]);
  }

  printf("\n");

  //printf("%ld\n", sizeof(prime) / sizeof(prime[0]));

  return 0;
}
