/**
 * source: https://chatgpt.com/g/g-p-693919539f8881918d2912e5d2a6c48f-learn-c/c/695c8352-034c-8320-9df5-315c273e66cb
 * context: Modify an array
 */

#include <stdio.h>

int main() {
    int arr[4] = {1, 2, 3, 4};

    printf("=== Before array modification ===\n");
    for (int i = 0; i < 4; i++) {
        printf("value of index %d => %d\n", i, arr[i]);
    }

    arr[0] = arr[1] + arr[2];
    arr[3] = arr[0] * 2;

    printf("\n\n");

    printf("=== After array modification ===\n");
    for (int i = 0; i < 4; i++) {
        printf("value of index %d => %d\n", i, arr[i]);
    }
   
    return 0;
}
