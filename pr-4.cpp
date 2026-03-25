#include <iostream>
using namespace std;


// Base Class
class BankAccount {

private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:

    BankAccount(int acc, string name, double bal) {
        accountNumber = acc;
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
        }
        else {
            cout << "Insufficient Balance\n";
        }
    }

    double getBalance() {
        return balance;
    }

    virtual void displayAccountInfo() {

        cout << "\n---------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    virtual void calculateInterest() {}

    virtual ~BankAccount() {}
};



// Savings Account
class SavingsAccount : public BankAccount {

private:
    double interestRate;

public:

    SavingsAccount(int acc, string name, double bal)
        : BankAccount(acc, name, bal) {

        interestRate = 4.0;

        cout << "Savings Account Created\n";
        cout << "Bank Interest Rate: 4%\n";
    }

    void calculateInterest() {

        double interest = getBalance() * interestRate / 100;

        deposit(interest);

        cout << "Savings Interest Added: "
             << interest << endl;
    }
};



// Checking Account
class CheckingAccount : public BankAccount {

private:
    double overdraftLimit;

public:

    CheckingAccount(int acc, string name, double bal)
        : BankAccount(acc, name, bal) {

        overdraftLimit = 5000;

        cout << "Checking Account Created\n";
        cout << "Bank Overdraft Limit: 5000\n";
    }

    void withdraw(double amount) {

        if (amount <= getBalance() + overdraftLimit) {
            BankAccount::withdraw(amount);
        }
        else {
            cout << "Overdraft Limit Exceeded\n";
        }
    }
};



// Fixed Deposit
class FixedDepositAccount : public BankAccount {

private:
    int term;
    double interestRate;
    double minimumBalance;

public:

    FixedDepositAccount(int acc, string name,
                        double bal, int t)
        : BankAccount(acc, name, bal) {

        interestRate = 7.0;
        minimumBalance = 10000;

        cout << "Fixed Deposit Created\n";
        cout << "Bank Interest Rate: 7%\n";
        cout << "Minimum Amount: 10000\n";
        cout << "Minimum Term: 6 Months\n";

        if (bal < minimumBalance)
            cout << "Warning: Minimum Balance Required\n";

        if (t < 6)
            cout << "Warning: Minimum Term Required\n";

        term = t;
    }

    void calculateInterest() {

        double interest =
        getBalance() * interestRate * term / 1200;

        deposit(interest);

        cout << "Fixed Deposit Interest Added: "
             << interest << endl;
    }
};



// Main
int main() {

    BankAccount* accounts[10];
    int count = 0;
    int choice;

    do {

        cout << "\n====== Banking System ======\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display All\n";
        cout << "7. Calculate Interest\n";
        cout << "8. Search Account\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {

            int acc;
            string name;
            double bal;

            cout << "Enter Account Number: ";
            cin >> acc;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Balance: ";
            cin >> bal;

            accounts[count++] =
            new SavingsAccount(acc, name, bal);

            break;
        }


        case 2: {

            int acc;
            string name;
            double bal;

            cout << "Enter Account Number: ";
            cin >> acc;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Balance: ";
            cin >> bal;

            accounts[count++] =
            new CheckingAccount(acc, name, bal);

            break;
        }


        case 3: {

            int acc, term;
            string name;
            double bal;

            cout << "Enter Account Number: ";
            cin >> acc;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Amount: ";
            cin >> bal;

            cout << "Enter Term (Months): ";
            cin >> term;

            accounts[count++] =
            new FixedDepositAccount(acc, name, bal, term);

            break;
        }


        case 4: {

            int acc;
            double amt;
            bool found = false;

            cout << "Enter Account Number: ";
            cin >> acc;

            cout << "Enter Amount: ";
            cin >> amt;

            for (int i = 0; i < count; i++) {

                if (accounts[i]->getAccountNumber() == acc) {
                    accounts[i]->deposit(amt);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account Not Found\n";

            break;
        }


        case 5: {

            int acc;
            double amt;
            bool found = false;

            cout << "Enter Account Number: ";
            cin >> acc;

            cout << "Enter Amount: ";
            cin >> amt;

            for (int i = 0; i < count; i++) {

                if (accounts[i]->getAccountNumber() == acc) {
                    accounts[i]->withdraw(amt);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account Not Found\n";

            break;
        }


        case 6: {

            for (int i = 0; i < count; i++)
                accounts[i]->displayAccountInfo();

            break;
        }


        case 7: {

            for (int i = 0; i < count; i++)
                accounts[i]->calculateInterest();

            break;
        }


        case 8: {

            int acc;
            bool found = false;

            cout << "Enter Account Number: ";
            cin >> acc;

            for (int i = 0; i < count; i++) {

                if (accounts[i]->getAccountNumber() == acc) {
                    accounts[i]->displayAccountInfo();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Account Not Found\n";

            break;
        }

        }

    } while (choice != 0);

    return 0;
}
