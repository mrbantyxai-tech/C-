#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful\n";
        } else {
            cout << "Insufficient Balance\n";
        }
    }

    virtual void calculateInterest() {
        cout << "No Interest\n";
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    virtual ~BankAccount() {}
};



// Savings Account
class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Savings Interest Added: " << interest << endl;
    }
};



// Checking Account
class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdraw Successful\n";
        } else {
            cout << "Overdraft Limit Exceeded\n";
        }
    }
};



// Fixed Deposit
class FixedDepositAccount : public BankAccount {
    int term;
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal) {
        term = t;
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate * term / 100;
        balance += interest;
        cout << "FD Interest Added: " << interest << endl;
    }
};



int main() {

    BankAccount* accounts[10];   // Dynamic pointer array
    int count = 0;
    int choice;

    do {
        cout << "\n===== Banking System =====\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display All\n";
        cout << "7. Calculate Interest\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int accNo;
        string name;
        double balance;

        switch (choice) {

        case 1: {
            double rate;
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> balance;
            cout << "Enter Interest Rate: ";
            cin >> rate;

            accounts[count++] =
                new SavingsAccount(accNo, name, balance, rate);
            break;
        }

        case 2: {
            double limit;
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> balance;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;

            accounts[count++] =
                new CheckingAccount(accNo, name, balance, limit);
            break;
        }

        case 3: {
            int term;
            double rate;
            cout << "Enter Account No: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Balance: ";
            cin >> balance;
            cout << "Enter Term: ";
            cin >> term;
            cout << "Enter Interest Rate: ";
            cin >> rate;

            accounts[count++] =
                new FixedDepositAccount(accNo, name, balance, term, rate);
            break;
        }

        case 4: {
            int acc;
            double amt;

            cout << "Enter Account No: ";
            cin >> acc;

            cout << "Enter Amount: ";
            cin >> amt;

            for (int i = 0; i < count; i++) {
                if (accounts[i]->getAccountNumber() == acc)
                    accounts[i]->deposit(amt);
            }
            break;
        }

        case 5: {
            int acc;
            double amt;

            cout << "Enter Account No: ";
            cin >> acc;

            cout << "Enter Amount: ";
            cin >> amt;

            for (int i = 0; i < count; i++) {
                if (accounts[i]->getAccountNumber() == acc)
                    accounts[i]->withdraw(amt);
            }
            break;
        }

        case 6:
            for (int i = 0; i < count; i++)
                accounts[i]->displayAccountInfo();
            break;

        case 7:
            for (int i = 0; i < count; i++)
                accounts[i]->calculateInterest();
            break;

        }

    } while (choice != 0);

    return 0;
}