#include <iostream>
using namespace std;
template <typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 5, b = 9;
    myswap(a, b);
    cout << "a: " << a << ", b: " << b << endl;
    return 0;
}