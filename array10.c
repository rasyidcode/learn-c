/**
 * source: https://chatgpt.com/g/g-p-693919539f8881918d2912e5d2a6c48f-learn-c/c/695c8352-034c-8320-9df5-315c273e66cb
 * context: hero levels
 */
#include <stdio.h>

int main() {
    int levels[] = {1, 3, 7, 10, 15};

    for (int i = 0; i < 5; i++) {
        printf("Hero %d level: %d\n", i+1, levels[i]);
    }

    return 0;
}
