#include <iostream>
using namespace std;
void printMenu()
{
    cout << "1. Help " << endl
         << "2. Exchange Stats " << endl
         << "3. Make an Offer " << endl
         << "4. Make a bid " << endl
         << "5. Print wallet " << endl
         << "6. Continue " << endl
         << endl;
    cout << "============================" << endl;
    cout << "Please choose (1-6)" << endl;
}
int getUserOption()
{
    int userOption;
    cin >> userOption;
    cout << "You choose: " << userOption << endl;
    return userOption;
}
void processUserOption(int userOption)
{
    switch (userOption)
    {

    case 1:
        cout << "Help - choose options from the menu" << endl;
        cout << "and follow the on screen instructions." << endl;
        break;
    case 2:
        cout << "Exchange stats loading..." << endl;
        break;
    case 3:
        cout << "Making an offer..." << endl;
        break;
    case 4:
        cout << "Making a bid..." << endl;
        break;
    case 5:
        cout << "Printing wallet..." << endl;
        break;
    case 6:
        cout << "Continuing" << endl;
        break;
    default:
        cout << "Invalid input!" << endl
             << endl
             << endl;
        break;
    }
}
int main()
{
    do
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    } while (true);

    return 0;
}
