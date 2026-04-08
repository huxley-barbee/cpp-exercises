/*
 * ## EXERCISE 1: Classes and Basic Encapsulation [2.b.i]
 * 
 * Write a program demonstrating basic class features.
 * 
 * **Requirements:**
 * 1. Create a BankAccount class with:
 *    - Private members: accountNumber, balance
 *    - Public constructor
 *    - Public methods: deposit(), withdraw(), getBalance()
 *    - Prevent negative balance
 * 2. Demonstrate encapsulation (cannot access private members directly)
 * 3. Create multiple instances
 * 4. Show member initialization list in constructor
 * 
 * **Expected output format:**
 * ```
 * Creating account 1001 with initial balance: $1000
 * Creating account 1002 with initial balance: $500
 * 
 * Account 1001 operations:
 * Depositing $200
 * New balance: $1200
 * Withdrawing $300
 * New balance: $900
 * 
 * Account 1002 operations:
 * Attempting to withdraw $600
 * Insufficient funds! Balance: $500
 * Balance remains: $500
 * 
 * Encapsulation: Cannot access balance directly (private member)
 * ```
 */

#include <iostream>

class BankAccount {

    private:
        std::string accountName;
        int balance;

    public:
        BankAccount(std::string name, int initial) : accountName(name), balance(initial) {
            std::cout << "Creating account " << accountName << " with inital balance: $"
                << balance << "\n";
        }

        void deposit(int amount) {
            balance += amount;
        }

        void withdraw(int amount) {
            if (amount > balance) {
                std::cout << "Insufficient funds! Balance: $" << balance << "\n";
                throw std::exception();
            } else {
                balance -= amount;
            }
        }

        int getBalance() {
            return balance;
        }

};

int main() {

    BankAccount one = BankAccount("1001", 1000);
    BankAccount two = BankAccount("1002", 500);

    std::cout << "\n";

    std::cout << "Account 1001 operations:\n";
    std::cout << "Depositing $200\n";
    one.deposit(200);
    std::cout << "New balance: $" << one.getBalance() << "\n";
    std::cout << "Withdrawing $300\n";
    one.withdraw(300);
    std::cout << "New balance: $" << one.getBalance() << "\n";

    std::cout << "\n";

    std::cout << "Account 1002 operations:\n";
    std::cout << "Attempting to withdraw $600\n";
    try {
        two.withdraw(600);
    } catch(std::exception e) {
        std::cout << "Balance remains: $" << two.getBalance() << "\n";
    }

    std::cout << "\n";
    std::cout << "Encapsulation: Cannot access balance directly (private member)\n";
    // error: 'balance' is a private member of 'BankAccount'
    // std::cout << two.balance;
}
