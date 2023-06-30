#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <limits>

/**
 * @class BankAccount
 * @brief Represents a bank account with basic operations such as deposit, withdrawal, and balance display.
 */
class BankAccount {
private:
    float balance;                    /**< The current balance of the account */
    std::string holder_name;          /**< The name of the account holder */
    static long account_number;       /**< The account number of the account */
    long my_account;                  /**< The unique account number assigned to this account */

public:
    /**
     * @brief Constructor to create a BankAccount object.
     * @param name The name of the account holder.
     */
    BankAccount(const std::string& name) : holder_name(name), balance(0.0f) {
        my_account = ++account_number;
    }

    /**
     * @brief Deposits money into the account.
     * @param money The amount of money to deposit.
     */
    void depositMoney(float money) {
        if (money < 0) {
            std::cout << "Error: You cannot deposit negative money. Please enter a non-negative value." << std::endl;
            return;
        }

        float maxFloat = std::numeric_limits<float>::max();
        if (balance > maxFloat - money) {
            std::cout << "Error: Float limit reached. Please enter a number lesser than " << (maxFloat - balance) << "." << std::endl;
            return;
        }

        balance += money;
        std::cout << "Deposit successful. Current balance: " << balance << std::endl;
    }

    /**
     * @brief Withdraws money from the account.
     * @param money The amount of money to withdraw.
     */
    void withdrawMoney(float money) {
        if (money > balance) {
            std::cout << "Error: Insufficient balance." << std::endl;
            return;
        }

        balance -= money;
        std::cout << "Withdrawal successful. Current balance: " << balance << std::endl;
    }

    /**
     * @brief Displays the account details.
     */
    void displayDetails() const {
        std::cout << "Hello " << holder_name << ":" << std::endl;
        std::cout << "Your account " << my_account << " has a balance of " << balance << " remaining to withdraw." << std::endl;
    }
};

// Initialize the static member variable
long BankAccount::account_number = 10000;

#endif
