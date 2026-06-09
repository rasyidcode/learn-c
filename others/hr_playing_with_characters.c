#include <stdio.h>

int main() {
    char ch;
    char s[20];
    char sen[100];

    printf("Input a single character: ");
    scanf("%c", &ch);

    printf("Input a string: ");
    scanf("%s", s);

    printf("Input a sentence: ");
    scanf("\n");
    scanf("%[^\n]%*c", sen);

    printf("Single char: %c\n", ch);
    printf("String: %s\n", s);
    printf("Sentence: %s\n", sen);

    return 0;
}
