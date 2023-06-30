#include "bank.h"

int main() {
    BankAccount account("John Doe");

    account.displayDetails();
    account.depositMoney(500.0f);
    account.withdrawMoney(200.0f);
    account.withdrawMoney(400.0f);
    account.depositMoney(-100.0f);

    return 0;
}