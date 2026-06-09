#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    char ch;
    bool new_sentence = true; // Flag to track sentence beginnings

    printf("=== Text Case Converter ===\n");
    printf("This program converts text to proper case format.\n");
    printf("Enter your text (press Ctrl+D on Unix or Ctrl+Z on Windows to finish\n\n");

    while ((ch = getchar()) != EOF) {
        if (new_sentence && isalpha(ch)) {
            // Capitalize first letter of sentences
            putchar(toupper(ch));
            new_sentence = false;
        } else if (isalpha(ch) && new_sentence) {
            // Capitalize if the previous char was sentence-ending punctuation
            putchar(toupper(ch));
            new_sentence = false;
        } else {
            // Convert other letters to lowercase
            if (isupper(ch)) {
                putchar(tolower(ch));
            } else {
                putchar(ch);
            }
        }

        // Check for end of sentence
        if (ch == '.' || ch == '!' || ch == '?') {
            new_sentence = true;
        }
    }

    printf("\n\n=== Conversion complete! ===\n");

    return 0;
}
