#include <iostream>
#include <iomanip>

class ATM {
private:
    std::string correctPin;
    double balance;
    bool isLoggedIn;

public:
    ATM() : correctPin("1234"), balance(1000.0), isLoggedIn(false) {}

    void checkPin(const std::string& pin) {
        if (!isLoggedIn) {
            if (pin == correctPin) {
                isLoggedIn = true;
                std::cout << "PIN correct. You are now logged in.\n";
                showOptions();
            } else {
                std::cout << "Incorrect PIN. Please try again.\n";
            }
        } else {
            std::cout << "You are already logged in. Logout first to enter a new PIN.\n";
        }
    }

    void showOptions() {
        std::cout << "Select Operation:\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Deposit\n";
        std::cout << "4. Logout\n";

        int choice;
        std::cout << "Enter the number of your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                logout();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                showOptions();
        }
    }

    void checkBalance() {
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
        showOptions();
    }

    void withdraw() {
        double amount;
        std::cout << "Enter withdrawal amount: $";
        std::cin >> amount;

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. Remaining Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds.\n";
        }

        showOptions();
    }

    void deposit() {
        double amount;
        std::cout << "Enter deposit amount: $";
        std::cin >> amount;

        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }

        showOptions();
    }

    void logout() {
        isLoggedIn = false;
        std::cout << "Logged out. Please enter PIN to log in again.\n";
    }
};

int main() {
    ATM atm;

    std::string enteredPin;
    std::cout << "Enter your PIN: ";
    std::cin >> enteredPin;

    atm.checkPin(enteredPin);

    return 0;
}
