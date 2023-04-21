#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount
{
private:
    string name;
    string mobile;
    string accountNumber;
    string pinNumber;
    double balance;

public:
    BankAccount(string n, string m, string p)
    {
        name = n;
        mobile = m;
        pinNumber = p;
        balance = 0;
        // Generate a random account number
        accountNumber = to_string(rand() % 10000);
    }
    void showDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Mobile: " << mobile << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit Successful. New Balance: " << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance < amount)
        {
            cout << "Insufficient Balance." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful. Withdrawn Amount: " << amount << endl;
            cout << "New Balance: " << balance << endl;
        }
    }
    bool verifyPin(string p)
    {
        return pinNumber == p;
    }
    void modifyDetails(string n, string m, string p)
    {
        name = n;
        mobile = m;
        pinNumber = p;
        cout << "Account Details Updated." << endl;
    }
    string getAccountNumber()
    {
        return accountNumber;
    }
};

class Bank
{
private:
    vector<BankAccount> accounts;

public:
    void openAccount()
    {
        string name, mobile, pin;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Mobile Number: ";
        getline(cin, mobile);
        cout << "Enter 4-digit PIN Number: ";
        getline(cin, pin);
        BankAccount account(name, mobile, pin);
        accounts.push_back(account);
        cout << "Account Created. Account Number: " << account.getAccountNumber() << endl;
    }
    void showDetails(string accountNumber, string pin)
    {
        bool found = false;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                if (accounts[i].verifyPin(pin))
                {
                    accounts[i].showDetails();
                }
                else
                {
                    cout << "Incorrect PIN." << endl;
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account not found." << endl;
        }
    }
    void deposit(string accountNumber, string pin, double amount)
    {
        bool found = false;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                if (accounts[i].verifyPin(pin))
                {
                    accounts[i].deposit(amount);
                }
                else
                {
                    cout << "Incorrect PIN." << endl;
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account not found." << endl;
        }
    }
    void withdraw(string accountNumber, string pin, double amount)
    {
        bool found = false;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                if (accounts[i].verifyPin(pin))
                {
                    accounts[i].withdraw(amount);
                }
                else
                {
                    cout << "Incorrect PIN." << endl;
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account not found." << endl;
        }
    }
    void modifyDetails(string accountNumber, string pin, string name, string mobile, string newPin)
    {
        bool found = false;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                if (accounts[i].verifyPin(pin))
                {
                    accounts[i].modifyDetails(name, mobile, newPin);
                }
                else
                {
                    cout << "Incorrect PIN." << endl;
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account not found." << endl;
        }
    }
    void deleteAccount(string accountNumber, string pin)
    {
        bool found = false;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getAccountNumber() == accountNumber)
            {
                if (accounts[i].verifyPin(pin))
                {
                    accounts.erase(accounts.begin() + i);
                    cout << "Account Deleted." << endl;
                }
                else
                {
                    cout << "Incorrect PIN." << endl;
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Account not found." << endl;
        }
    }
};

int main()
{
    Bank bank;
    int choice;
    do
    {
        cout << "======================" << endl;
        cout << "Bank Management System" << endl;
        cout << "======================" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Show Account Details" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Modify Account Details" << endl;
        cout << "6. Delete Account" << endl;
        cout << "0. Exit" << endl;
        cout << "======================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            bank.openAccount();
            break;
        }
        case 2:
        {
            string accountNumber, pin;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter PIN: ";
            getline(cin, pin);
            bank.showDetails(accountNumber, pin);
            break;
        }
        case 3:
        {
            string accountNumber, pin;
            double amount;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter PIN: ";
            getline(cin, pin);
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            bank.deposit(accountNumber, pin, amount);
            break;
        }
        case 4:
        {
            string accountNumber, pin;
            double amount;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter PIN: ";
            getline(cin, pin);
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            bank.withdraw(accountNumber, pin, amount);
            break;
        }
        case 5:
        {
            string accountNumber, pin, name, mobile, newPin;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter PIN: ";
            getline(cin, pin);
            cout << "Enter New Name: ";
            getline(cin, name);
            cout << "Enter New Mobile Number: ";
            getline(cin, mobile);
            cout << "Enter New PIN: ";
            getline(cin, newPin);
            bank.modifyDetails(accountNumber, pin, name, mobile, newPin);
            break;
        }
        case 6:
        {
            string accountNumber, pin;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter PIN: ";
            getline(cin, pin);
            bank.deleteAccount(accountNumber, pin);
            break;
        }
        case 0:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice. Try again." << endl;
        }
        }
    } while (choice != 0);
    return 0;
}
