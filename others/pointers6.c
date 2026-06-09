#include <stdio.h>

void deposit(float *balance, float amount);

void withdraw(float *balance, float amount);

int main() {
    float balance = 1000.0;

    printf("Initial balance: %.2f\n", balance);

    deposit(&balance, 500.0);
    withdraw(&balance, 300.0);
 
    return 0;
}

void deposit(float *balance, float amount) {
    *balance = *balance + amount;
    printf("Balance after deposit: %.2f\n", *balance);
}

void withdraw(float *balance, float amount) {
    if (*balance >= amount) {
        *balance = *balance - amount;
        printf("Balance after withdrawal: %.2f\n", *balance);
    } else {
        printf("Insufficient funds!\n");
    }
}
