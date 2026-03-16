#include <iostream>
#include <cstring>

using namespace std;

class BankAccount {
    double balance;
    char accountHolder[50] = {0};
public:
    BankAccount(double inputBalance, const char* inputName);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
};

int main(void) {
    double inputBalance;
    char inputName[50] = {0};

    cout << "Enter account holder's name: ";
    cin.getline(inputName, 50);
    cout << "Enter initial balance: ";
    cin >> inputBalance;

    BankAccount account1(inputBalance, inputName);

    cout << "Account holder: " << inputName << endl;
    cout << "Initial balance: $" << account1.getBalance() << endl;

    account1.deposit(100.0);
    cout << "Balance after deposit: $" << account1.getBalance() << endl;
    account1.withdraw(50.0);
    cout << "Balance after withdrawal: $" << account1.getBalance() << endl;

    return 0;
}

BankAccount::BankAccount(double inputBalance, const char* inputName) {
    balance = inputBalance;
    strcpy(accountHolder, inputName);
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient funds!" << endl;
    } else {
        balance -= amount;
    }
}

double BankAccount::getBalance() const {
    return balance;
}