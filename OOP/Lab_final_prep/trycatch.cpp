/*try {
    Code that might cause an exception
    if (somethingGoesWrong)
        throw error_value;
}
catch (Type variable) {
    Code to handle the error
}
  Whener you throw a direct string, you catch a const char* error!
*/

#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 404;
    }
    catch (int errorCode)
    {
        cout << "Error code: " << errorCode << endl;
    }

    return 0;
}