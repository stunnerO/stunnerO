#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    void createAccount();
    void showAccount() const;
    void deposit(double);
    void withdraw(double);
    int getAccountNumber() const;
    double getBalance() const;
};

void Account::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Initial Deposit: ";
    cin >> balance;
    cout << "\nAccount Created.\n";
}

void Account::showAccount() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << name << endl;
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Amount Deposited: $" << fixed << setprecision(2) << amount << endl;
        cout << "New Balance: $" << fixed << setprecision(2) << balance << endl;
    } else {
        cout << "Invalid amount.\n";
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Amount Withdrawn: $" << fixed << setprecision(2) << amount << endl;
        cout << "New Balance: $" << fixed << setprecision(2) << balance << endl;
    } else {
        cout << "Invalid amount or insufficient funds.\n";
    }
}

int Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

void createNewAccount(Account &account) {
    account.createAccount();
    ofstream outFile;
    outFile.open("accounts.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char *>(&account), sizeof(Account));
    outFile.close();
}

void displayAccountDetails(int accNum) {
    Account account;
    ifstream inFile;
    inFile.open("accounts.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened. Press any key to exit.";
        return;
    }
    bool found = false;
    while (inFile.read(reinterpret_cast<char *>(&account), sizeof(Account))) {
        if (account.getAccountNumber() == accNum) {
            account.showAccount();
            found = true;
        }
    }
    inFile.close();
    if (!found) {
        cout << "Account not found.\n";
    }
}

void depositToAccount(int accNum, double amount) {
    Account account;
    fstream file;
    file.open("accounts.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File could not be opened. Press any key to exit.";
        return;
    }
    bool found = false;
    while (!file.eof() && found == false) {
        file.read(reinterpret_cast<char *>(&account), sizeof(Account));
        if (account.getAccountNumber() == accNum) {
            account.deposit(amount);
            int pos = (-1) * static_cast<int>(sizeof(account));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&account), sizeof(Account));
            found = true;
        }
    }
    file.close();
    if (!found) {
        cout << "Account not found.\n";
    }
}

void withdrawFromAccount(int accNum, double amount) {
    Account account;
    fstream file;
    file.open("accounts.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File could not be opened. Press any key to exit.";
        return;
    }
    bool found = false;
    while (!file.eof() && found == false) {
        file.read(reinterpret_cast<char *>(&account), sizeof(Account));
        if (account.getAccountNumber() == accNum) {
            account.withdraw(amount);
            int pos = (-1) * static_cast<int>(sizeof(account));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&account), sizeof(Account));
            found = true;
        }
    }
    file.close();
    if (!found) {
        cout << "Account not found.\n";
    }
}

int main() {
    Account account;
    int choice, accNum;
    double amount;
    do {
        cout << "\n\n\tBANK MANAGEMENT SYSTEM";
        cout << "\n\n\t1. New Account";
        cout << "\n\t2. Deposit Amount";
        cout << "\n\t3. Withdraw Amount";
        cout << "\n\t4. Balance Enquiry";
        cout << "\n\t5. Exit";
        cout << "\n\n\tSelect Your Option (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            createNewAccount(account);
            break;
        case 2:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            depositToAccount(accNum, amount);
            break;
        case 3:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            withdrawFromAccount(accNum, amount);
            break;
        case 4:
            cout << "Enter Account Number: ";
            cin >> accNum;
            displayAccountDetails(accNum);
            break;
        case 5:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid option. Try again.";
        }
    } while (choice != 5);

    return 0;
}
