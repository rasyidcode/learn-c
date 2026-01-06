/**
 * source: https://chatgpt.com/g/g-p-693919539f8881918d2912e5d2a6c48f-learn-c/c/695c8352-034c-8320-9df5-315c273e66cb
 * context: Write code
 */
#include <stdio.h>

int main() {
    int myArr[] = {2, 3, 5, 7, 11};
    int sum;

    for(int i = 0; i < 5; i++) {
        sum += myArr[i];
    }

    printf("%d\n", sum);

    return 0;
}
