#include <iostream>
using namespace std;

int main()
{
    do
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

        int userOption;
        cin >> userOption;
        cout << "You choose: " << userOption << endl;
        
        if (userOption == 1)
        {
            cout << "Follow the on screen instructions" << endl;
        }
        else if (userOption == 2)
        {
            cout << "Exchange stats loading..." << endl;
        }
        else if (userOption == 3)
        {
            cout << "Making an offer..." << endl;
        }
        else if (userOption == 4)
        {
            cout << "Making a bid..." << endl;
        }
        else if (userOption == 5)
        {
            cout << "Printing wallet..." << endl;
        }
        else if (userOption == 6)
        {
            cout << "Continuing" << endl;
        }

        if (userOption == 0 || userOption > 6 || userOption < 1)
        {
            cout << "Invalid input!" << endl;
        }
    } while (true);
    return 0;
}