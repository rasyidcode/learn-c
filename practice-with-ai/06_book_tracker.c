// Type: Practice Struct
// AI-Assited: Codex
#include <stdio.h>
#include <string.h>

struct Book {
  char title[100];
  char author[100];
  int year;
  int isBorrowed;
};

void printBook(struct Book book) {
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Year: %d\n", book.year);
  printf("Status: %s\n", book.isBorrowed == 0 ? "Available" : "Borrowed");
}

int main(void) {
  struct Book books[3];
  int bookToBorrow;

  printf("\n\n");
  for (int i = 0; i < 3; i++) {
    printf("Enter Book #%d Information: \n", i + 1);

    printf("Title: ");
    if (fgets(books[i].title, sizeof(books[i].title), stdin) != NULL) {
      books[i].title[strcspn(books[i].title, "\n")] = '\0';
    }

    printf("Author: ");
    if (fgets(books[i].author, sizeof(books[i].author), stdin)) {
      books[i].author[strcspn(books[i].author, "\n")] = '\0';
    }

    printf("Year: ");
    if (scanf("%d", &books[i].year) != 1) {
        printf("Invalid year. Setting it to 0.\n");
        books[i].year = 0;
    }

    // remove newline in the buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    books[i].isBorrowed = 0;

    printf("\n");
  }

  printf("\n\n=== All books ===\n\n");
  for (int i = 0; i < 3; i++) {
    printf("Book #%d\n", i + 1);
    printBook(books[i]);
    printf("==========================\n\n");
  }

  printf("Which book you want to borrow? (1/2/3): ");
  if (scanf("%d", &bookToBorrow) == 1) {
    if (bookToBorrow >= 1 && bookToBorrow <= 3) {
      if (books[bookToBorrow - 1].isBorrowed == 0) {
        books[bookToBorrow - 1].isBorrowed = 1;
      }
    } else {
      printf("Invalid book number\n");
    }
  } else {
    printf("Invalid input\n");
  }

  printf("=== All books ===\n\n");
  for (int i = 0; i < 3; i++) {
    printf("Book #%d\n", i + 1);
    printBook(books[i]);
    printf("==========================\n\n");
  }

  return 0;
}
