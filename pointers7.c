#include <stdio.h>

float deposit(float balance, float amount);

float withdraw(float balance, float amount);

int main() {
    float balance = 1000.0;

    printf("Initial balance: %.2f\n", balance);

    balance = deposit(balance, 500.0);
    balance = withdraw(balance, 300.0);
 
    return 0;
}

float deposit(float balance, float amount) {
    balance = balance + amount;
    printf("Balance after deposit: %.2f\n", balance);
    return balance;
}

float withdraw(float balance, float amount) {
    if (balance >= amount) {
        balance = balance - amount;
        printf("Balance after withdrawal: %.2f\n", balance);
    } else {
        printf("Insufficient funds!\n");
    }
    return balance;
}
