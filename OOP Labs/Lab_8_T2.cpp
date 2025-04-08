#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount()
    {
        balance = 1000.0;
    }

    void showBalance() const
    {
        cout << "Current Balance: $" << balance << endl;
    }
};

void authenticateUser(const string &correctUsername, const string &correctPassword, BankAccount &account)
{
    string enteredUsername;
    string enteredPassword;

    cout << "Username: ";
    cin >> enteredUsername;
    cout << "Password: ";
    cin >> enteredPassword;
    cout << "\n";

    if (enteredUsername == correctUsername && enteredPassword == correctPassword)
    {
        account.showBalance();
    }
    else
    {
        cout << "Invalid username or password!" << endl;
    }
}

int main()
{
    string username = "hamza";
    string password = "2024206";

    BankAccount userAccount;

    authenticateUser(username, password, userAccount);

    return 0;
}
