#include <stdio.h>

int main(void) {
    // an array storing different ages
    int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};

    float avg, sum = 0;
    int i;

    // get the length of the array
    int length = sizeof(ages) / sizeof(ages[0]);

    // loop through the elements of the array
    for (i = 0; i < length; i++) {
        sum += ages[i];
    }

    // calculate the average by dividing the sum by the length
    avg = sum / length;
    
    // print the average
    printf("The average age is %.2f\n", avg);

    // -- find the lowest age among different ages

    // create a variable and assign the first array element of ages to it
    int lowest_age = ages[0];

    // loop through the elements of the ages array to find the lowest age
    for (i = 0; i < length; i++) {
        if (lowest_age > ages[i]) {
            lowest_age = ages[i];
        }
    }
    printf("The lowest age is %d\n", lowest_age);

    // -- find the highest age among different ages

    // create a variable and assign the first array element of ages to it
    int highest_age = ages[0];

    // loop through the elements of the ages array to find the highest age
    for (i = 0; i < length; i++) {
        if (highest_age < ages[i]) {
            highest_age = ages[i];
        }
    }
    printf("The highest age is %d\n", highest_age);

    return 0;
}
