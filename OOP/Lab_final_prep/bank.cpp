#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
template <typename T>
class Account
{
protected:
    T accountNumber;
    float balance;

public:
    void saveDetails(const Account &other)
    {
        ofstream ufile;
        ufile.open("Accounts.txt");
        try
        {
            if (!ufile)
            {
                throw "Error in opening file";
            }
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
        ufile << other.accountNumber << "," << other.balance << endl;
        ufile.close();
    }
    void readFile()
    {
        {
            ifstream ufile;
            ufile.open("Accounts.txt");
            try
            {
                if (!ufile)
                {
                    throw "Error in opening file";
                }
            }
            catch (const char *e)
            {
                cout << e << endl;
            }
            string line;
            while (getline(ufile, line))
            {

                string part1, part2;

                stringstream ss(line);

                // Get part before comma
                getline(ss, part1, ',');

                // Get part after comma
                getline(ss, part2, ',');

                cout << "Part 1: " << part1 << endl;
                cout << "Part 2: " << part2 << endl;
            }
            cout << "File succesfully output! \n";
            ufile.close();
        }
    }
    Account(T accountNumber, float balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    virtual void Withdraw(float amount)
    {
        try
        {
            if (amount <= balance)
            {
                balance -= amount;
                cout << "Withdrawal Successful: " << amount << endl;
            }
            else
                throw "Insufficient Balance! ";
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
    void Deposit(float amount)
    {
        try
        {
            if (amount >= 0)
            {
                balance += amount;
                cout << "Withdrawal Successful: " << amount << endl;
            }
            else
                throw "Negative Deposit not allowed! ";
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
    void Display()
    {
        cout << accountNumber << endl;
        cout << balance << endl;
    }
    template <typename U>
    friend void transferFunds(Account<U> &from, Account<U> &to, float amount);
};
template <typename T>
class SavingsAccount : public Account<T>
{
public:
    SavingsAccount(T accountNumber, float balance) : Account<T>(accountNumber, balance) {}

    void Withdraw(float amount)
    {
        try
        {
            if (Account<T>::balance - amount >= 500)
            {
                Account<T>::balance -= amount;
                cout << "Withdrawal Successful: " << amount << endl;
            }
            else
                throw "Insufficient Balance! ";
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
    template <typename U>
    friend void transferFunds(Account<U> &from, Account<U> &to, float amount);
};
template <typename T>
void transferFunds(Account<T> &from, Account<T> &to, float amount)
{
    if (from.balance - amount > 0)
    {
        to.balance += amount;
        from.balance -= amount;
    }
}
int main()
{
    SavingsAccount<int> sa(12345, 1000);
    sa.Deposit(500);
    sa.Withdraw(200);
    sa.Display();

    Account<int> acc1(111, 1000), acc2(222, 500);
    transferFunds(acc1, acc2, 300);
    acc1.Display();
    acc2.Display();

    sa.saveDetails(sa);
    sa.readFile();

    return 0;
}
