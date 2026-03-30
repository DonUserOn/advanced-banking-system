#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;
    int pin;
    vector<string> history;

public:
    BankAccount() {
        balance = 0;
        pin = 1234;
        loadFromFile();
    }

    bool login(int inputPin) {
        return inputPin == pin;
    }

    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            history.push_back("Deposited: " + to_string(amount));
            cout << "Deposit successful!\n";
            saveToFile();
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(double amount) {
        if(amount > balance || amount <= 0) {
            cout << "Invalid or insufficient funds!\n";
        } else {
            balance -= amount;
            history.push_back("Withdrew: " + to_string(amount));
            cout << "Withdrawal successful!\n";
            saveToFile();
        }
    }

    void showBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void showHistory() {
        cout << "\nTransaction History:\n";
        for(const auto &h : history) {
            cout << "- " << h << endl;
        }
    }

    void saveToFile() {
        ofstream file("balance.txt");
        file << balance;
        file.close();
    }

    void loadFromFile() {
        ifstream file("balance.txt");
        if(file.is_open()) {
            file >> balance;
        }
        file.close();
    }
};

int main() {
    BankAccount account;

    int inputPin;
    cout << "Enter your PIN: ";
    cin >> inputPin;

    if(!account.login(inputPin)) {
        cout << "Wrong PIN!\n";
        return 0;
    }

    cout << "Login successful!\n";

    int choice;
    double amount;

    do {
        cout << "\n====== BANK MENU ======\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                account.showBalance();
                break;
            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 3:
                cout << "Enter amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 4:
                account.showHistory();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}