#include <stdio.h>

int main(void) {
    // -- initialize an array
    int myNumbers[] = {20, 15, 23, 50};

    // -- access the element of an array
    printf("The element of an array is: %d\n", myNumbers[0]);

    // -- change an array element
    printf("Before changing the second element of an array: %d\n", myNumbers[1]);
    myNumbers[1] = 25;
    printf("After changing the second element of an array: %d\n", myNumbers[1]);

    // -- set an array size
    int anime_episodes[4];
    anime_episodes[0] = 1170; // one piece
    anime_episodes[1] = 720; // naruto
    anime_episodes[2] = 366; // bleach
    anime_episodes[3] = 191; // jojo

    printf("One piece has %d total episodes\n", anime_episodes[0]);

    // -- get array size
    int pl_years[] = {
        1972, // C
        1985, // C++
        2009, // Go
        2000, // C#
        1995, // Java
        2016, // Zig
    };
    printf("Total number of bytes of pl_years is %zu\n", sizeof(pl_years));

    // -- get the number of elements
    int pl_years_length = sizeof(pl_years) / sizeof(pl_years[0]);
    printf("Number of elements of pl_years is %d\n", pl_years_length);

    // -- get array size (float)
    float ratings[] = {3.4, 4.5, 5.0, 1.2, 2.3};
    int ratings_length = sizeof(ratings) / sizeof(ratings[0]);
    printf("Total element of ratings is %d\n", ratings_length);

    // -- get array size (char)
    char grades[] = {'A', 'B', 'C', 'D', 'E'};
    int grades_length = sizeof(grades) / sizeof(grades[0]);
    printf("Total element of grades is %d\n", grades_length);

    // -- get array size (string)
    char *pl_names[] = {
        "C",
        "C++",
        "C#",
        "Go",
        "Zig"
    };
    int pl_names_length = sizeof(pl_names) / sizeof(pl_names[0]);
    printf("Total element of pl_names is %d\n", pl_names_length);

    // -- loop through an array
    for (int i = 0; i < 4; i++) {
        printf("Episodes for anime #%d is %d\n", i+1, anime_episodes[i]);
    }

    for (int i = 0; i < pl_years_length; i++) {
        printf("Founded years of programming language #%d is %d\n", i+1, pl_years[i]);
    }

    for (int i = 0; i < ratings_length; i++) {
        printf("Ratings for store #%d is %.1f\n", i+1, ratings[i]);
    }

    for (int i = 0; i < grades_length; i++) {
        printf("Grades for student #%d is %c\n", i+1, grades[i]);
    }

    for (int i = 0; i < pl_names_length; i++) {
        printf("%d. %s\n", i+1, pl_names[i]);
    }

    return 0;
}
