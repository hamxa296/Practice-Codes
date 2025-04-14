#include <iostream>
#include <string>
using namespace std;

template <typename T>
void swapAndCompare(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;

    cout << "After swapping: a = " << a << ", b = " << b << endl;

    if (a > b)
        cout << "a is greater than b" << endl;
    else if (a < b)
        cout << "b is greater than a" << endl;
    else
        cout << "a is equal to b" << endl;
}

int main()
{
    int a1 = 5, b1 = 10;
    swapAndCompare(a1, b1);

    string a2 = "Apple", b2 = "Banana";
    swapAndCompare(a2, b2);

    float a3 = 3.5, b3 = 2.1;
    swapAndCompare(a3, b3);

    return 0;
}
