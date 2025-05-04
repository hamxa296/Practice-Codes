#include <iostream>
using namespace std;
class BankManager;
class Account
{
protected:
    double balance;

public:
    Account(double balance)
    {
        this->balance = balance;
    }
    virtual void displayDetails() const = 0;
    friend void transferFunds(Account &from, Account &to, double amount);
    Account(const Account &other)
    {
        balance = other.balance;
    }
    friend class BankManager;
    virtual ~Account() {}
};
class SavingsAccount : public Account
{
    double rate;

public:
    SavingsAccount(double balance, double rate) : Account(balance)
    {
        if (balance < 5000)
        {
            cout << "Balance too low!\nNo returns expected!";
            this->rate = 1;
        }
        else
        {
            this->rate = 1 + rate;
        }
    }
    bool operator<(const SavingsAccount &other)

    {
        if (balance < other.balance)
            return 1;
        else
            return 0;
    }
    void displayDetails() const
    {
        cout << balance << endl;
        cout << rate << endl;
    };
    friend class BankManager;
};
class CheckingsAccount : public Account
{
    double overdraft;

public:
    CheckingsAccount(double balance, double overdraft) : Account(balance)
    {
        if (overdraft > 5000)
        {
            cout << "Overdraft too high!\nError expected!";
            this->overdraft = 1;
        }
        else
        {
            this->overdraft = overdraft;
        }
    }
    bool operator<(const CheckingsAccount &other)
    {
        if (balance < other.balance)
            return 1;
        else
            return 0;
    }
    void displayDetails() const
    {
        cout << balance << endl;
        cout << overdraft << endl;
    };
    friend class BankManager;
};
class BankManager
{
    string password = "abc123";

public:
    bool Authentication()
    {
        string password;
        cout << "Enter password: \n";
        cin >> password;
        if (this->password == password)
            return 1;
        else
            return 0;
    }
    void ViewAccount(const Account &other)
    {
        if (Authentication())
        {
            cout << other.balance;
        }
    }
    void CreatAccount(Account *newacc)
    {
        if (Authentication())
        {

            int choice;
            cout << "Press 1 for Savings \nPress 2 for Checkings: \n";
            cin >> choice;
            if (choice == 1)
            {
                newacc = new SavingsAccount(10000, 0.05);
            }
            else if (choice == 2)
            {
                newacc = new CheckingsAccount(500, 70);
            }
        }
    }
    void DeleteAccount(Account *other)
    {
        if (Authentication())
        {
            delete other;
        }
    }
};
int main()
{

    Account *newacc = nullptr;
    BankManager manager;
    manager.CreatAccount(newacc);

    if (newacc)
    {
        newacc->displayDetails();
        manager.DeleteAccount(newacc);
    }
    delete newacc;
    return 0;
}