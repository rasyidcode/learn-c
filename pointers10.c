#include <stdio.h>

float updateTemperature(float temp) {
    return temp + 2.5; // increase temperature
}

int main() {
    float roomTemp = 25.0;    

    printf("Initial Temperature: %.2f°C\n", roomTemp);

    roomTemp = updateTemperature(roomTemp);

    printf("Updated Temperature: %.2f°C\n", roomTemp);

    return 0;
}

