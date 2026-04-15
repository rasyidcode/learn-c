#include <stdio.h>

void updateTemperature(float *temp) {
    *temp = *temp + 2.5; // increase temperature
}

int main() {
    float roomTemp = 25.0;    

    printf("Initial Temperature: %.2f°C\n", roomTemp);

    updateTemperature(&roomTemp); // pass pointer

    printf("Updated Temperature: %.2f°C\n", roomTemp);

    return 0;
}

