#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Transaction {
    string type;
    double amount;
    double balanceAfter;
};

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
vector<Transaction> history;

public:
    BankAccount(string name, int number, double initialBalance) {
        accountHolder = name;
        accountNumber = number;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!\n";
            return;
        }

        balance += amount;
        history.push_back({"Deposit", amount, balance});

        cout << fixed << setprecision(2);
        cout << "Deposit successful! New balance: Rs. "
             << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        }
 else if (amount > balance) {
            cout << "Insufficient balance!\n";
        }
        else {
            balance -= amount;
            history.push_back({"Withdrawal", amount, balance});

            cout << fixed << setprecision(2);
            cout << "Withdrawal successful! Remaining balance: Rs. "
                 << balance << "\n";
        }
    }

    void displayDetails() {
        cout << "\n========== ACCOUNT DETAILS ==========\n";
        cout << "Account Holder : " << accountHolder << "\n";
        cout << "Account Number : " << accountNumber << "\n";
        cout << fixed << setprecision(2);
        cout << "Current Balance: Rs. " << balance << "\n";
        cout << "=====================================\n";
    }

    void showTransactionHistory() {
        cout << "\n========== TRANSACTION HISTORY ==========\n";

        if (history.empty()) {
            cout << "No transactions yet.\n";
            return;
        }

        for (int i = 0; i < history.size(); i++) {
            cout << i + 1 << ". "
                 << history[i].type
                 << " | Amount: Rs. " << history[i].amount
                 << " | Balance: Rs. " << history[i].balanceAfter
                 << "\n";
        }

        cout << "========================================\n";
    }
};

int main() {
    string name;
    int accountNumber;
    double initialBalance;
 cout << "=====================================\n";
    cout << "       WELCOME TO MINI BANK          \n";
    cout << "=====================================\n";

    cout << "Enter account holder name: ";
    getline(cin, name);

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter initial balance: Rs. ";
    cin >> initialBalance;

    if (initialBalance < 0) {
        cout << "Initial balance cannot be negative.\n";
        return 0;
    }

    BankAccount account(name, accountNumber, initialBalance);

    int choice;

    do {
        cout << "\n============= MAIN MENU =============\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. View Account Details\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter deposit amount: Rs. ";
                cin >> amount;
                account.deposit(amount);
                break;
            }
case 2: {
                double amount;
                cout << "Enter withdrawal amount: Rs. ";
                cin >> amount;
                account.withdraw(amount);
                break;
            }

            case 3:
                account.displayDetails();
                break;

            case 4:
                account.showTransactionHistory();
                break;

            case 5:
                cout << "Thank you for using Mini Bank!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
