#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Total number of arguments: %d\n", argc);

  printf("Program name: %s\n", argv[0]);

  if (argc > 1) {
    printf("The first argument is: %s\n", argv[1]);
  }

  for (int i = 0; i < argc; i++) {
    printf("Argument %d: %s\n", i, argv[i]);
  }

  return 0;
}
