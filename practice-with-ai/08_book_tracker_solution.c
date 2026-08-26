// AI-Assited: Codex
#include <stdio.h>
#include <string.h>

#define BOOK_COUNT 3

struct Book {
  char title[100];
  char author[100];
  int year;
  int isBorrowed;
};

void clearInputBuffer() {
  int ch;

  while ((ch = getchar()) != '\n' && ch != EOF) {
  }
}

void readText(const char prompt[], char text[], int size) {
  printf("%s", prompt);

  if (fgets(text, size, stdin) != NULL) {
    text[strcspn(text, "\n")] = '\0';
  }
}

int readNumber(const char prompt[]) {
  int number;

  while (1) {
    printf("%s", prompt);

    if (scanf("%d", &number) == 1) {
      clearInputBuffer();
      return number;
    }

    printf("Invalid input. Please enter a valid number.\n");
    clearInputBuffer();
  }
}

void printBook(struct Book book) {
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Year: %d\n", book.year);
  printf("Status: %s\n", book.isBorrowed == 0 ? "Available" : "Borrowed");
}

int main(void) {
  struct Book books[BOOK_COUNT];
  int bookToBorrow;

  printf("\n\n");
  for (int i = 0; i < BOOK_COUNT; i++) {
    printf("\nEnter Book #%d Information: \n", i + 1);

    readText("Title: ", books[i].title, sizeof(books[i].title));
    readText("Author: ", books[i].author, sizeof(books[i].author));

    books[i].year = readNumber("Year: ");
    books[i].isBorrowed = 0;
  }

  printf("\n=== All books ===\n\n");
  for (int i = 0; i < BOOK_COUNT; i++) {
    printf("Book #%d\n", i + 1);
    printBook(books[i]);
    printf("----------------------\n");
  }

  while (1) {
    bookToBorrow = readNumber("Which book you want to borrow? (1-3): ");
    if (bookToBorrow >= 1 && bookToBorrow <= BOOK_COUNT) {
      if (books[bookToBorrow - 1].isBorrowed == 0) {
        books[bookToBorrow - 1].isBorrowed = 1;
        printf("You borrowed \"%s\".\n", books[bookToBorrow - 1].title);
        break;
      }

      printf("That book is already borrowed.\n");
    }

    printf("Invalid book number.\n");
  }

  printf("\n=== Updated books list ===\n\n");
  for (int i = 0; i < 3; i++) {
    printf("Book #%d\n", i + 1);
    printBook(books[i]);
    printf("----------------------\n");
  }
}
