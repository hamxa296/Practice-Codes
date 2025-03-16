#include <iostream>
using namespace std;
void recursive(int num)
{
    if (num == 1)
        return;
    if (num % 2 == 0)
    {
        num /= 2;
    }
    else if (num % 2 != 0)
    {
        num = 3 * num + 1;
    }
    cout << "Current number: " << num << endl;
    return recursive(num);
}
int main()
{
    recursive(9);
    return 0;
}