#include <stdio.h>

void updateTemperature(float *temp) {
    *temp = *temp + 2.5; // increase temperature
}

int main() {
    float roomTemp = 25.0;    

    float *tempPtr = &roomTemp; // pointer to temperature
 
    printf("Initial Temperature: %.2f°C\n", roomTemp);

    updateTemperature(tempPtr); // pass pointer

    printf("Updated Temperature: %.2f°C\n", roomTemp);

    return 0;
}

