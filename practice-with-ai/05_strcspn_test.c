#include <stdio.h>
#include <string.h>

// AI-Assited: Gemini Web Search
int main(void) {
    char name[100] = "Ahmad J Rasyid";
    char position[20] = "Staff";

    printf("%zu\n", strcspn(name, "J"));
    printf("Position of t on \"Staff\" string is: %zu\n", strcspn(position, "t"));
    return 0;
}
