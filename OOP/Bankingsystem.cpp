#include <iostream>
using namespace std;
class BankAccount
{
protected:
    int AccountNo;
    double AccountBalance;
    string AccountHolder;

public:
    BankAccount(int AccountNo, double AccountBalance, string AccountHolder)
    {
        this->AccountNo = AccountNo;
        this->AccountBalance = AccountBalance;
        this->AccountHolder = AccountHolder;
    }
    virtual void DisplayInfo()
    {
        cout << "Account Number: " << AccountNo << endl;
        cout << "Account Holdeer: " << AccountHolder << endl;
        cout << "Account Balance: " << AccountBalance << endl;
    }
    void SetAccountBalance()
    {
        double accountbalance;
        cout << "Enter new account balance: " << endl;
        cin >> accountbalance;
        AccountBalance = accountbalance;
    }
};
class CurrentBankAccount : public BankAccount
{
protected:
    double overdraft_amount;

public:
    CurrentBankAccount(int AccountNo, double AccountBalance, string AccountHolder, double overdraft) : BankAccount(AccountNo, AccountBalance, AccountHolder)
    {

        this->overdraft_amount = overdraft;
    }
    void DisplayInfo()
    {
        cout << "Account Number: " << AccountNo << endl;
        cout << "Account Holdeer: " << AccountHolder << endl;
        cout << "Account Balance: " << AccountBalance << endl;
        cout << "Overdrafting Amount: " << overdraft_amount << endl;
    }
    void SetAccountBalance()
    {
        BankAccount::SetAccountBalance();
    }
};
class SavingsBankAccount : public BankAccount
{
    double interest_rate;

public:
    SavingsBankAccount(int AccountNo, double AccountBalance, string AccountHolder, double interest_rate) : BankAccount(AccountNo, AccountBalance, AccountHolder)
    {

        this->interest_rate = interest_rate;
    }
    void DisplayInfo()
    {
        cout << "Account Number: " << AccountNo << endl;
        cout << "Account Holdeer: " << AccountHolder << endl;
        cout << "Account Balance: " << AccountBalance << endl;
        cout << "Interest Rate: " << interest_rate << endl;
    }
    void SetAccountBalance()
    {
        BankAccount::SetAccountBalance();
    }
};
void showmenue()
{
    cout << "Enter what do you want to do: \n1. Open Current Account \n2. Open Savings Account \n3. Exit Program :)\n\n\n\n\n";
    
}
int main()
{

    CurrentBankAccount C1(1, 30, "ha", 399);
    C1.SetAccountBalance();
    return 0;
}