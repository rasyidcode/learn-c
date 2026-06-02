#include <stdio.h>

struct Person {
  char name[20]; 
  int age;
  int height;
};

int main(void) {  
  struct Person p1 = {"James", 30, 160};
  struct Person p2 = {"Iprit", 30, 155};

  printf("Person 1\n==========\n");
  printf("[Name]->%s\t[Age]->%d\t[Height]->%d\n", p1.name, p1.age, p1.height);
  printf("\n\n");
  printf("Person 2\n==========\n");
  printf("[Name]->%s\t[Age]->%d\t[Height]->%d\n", p2.name, p2.age, p2.height);

  return 0;
}
