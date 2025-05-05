#include <iostream>
using namespace std;
class DynamicArray
{
    int *ptr = nullptr;
    int size;

public:
    DynamicArray(int arraySize)
    {
        size = arraySize;
        ptr = new int[size];
        cout << "Dynamic Array created with size: " << size << endl;
    }
    int *get_ptr()
    {
        return ptr;
    }
    ~DynamicArray()
    {
        cout << "Destructor called! " << endl;
        delete[] ptr;
    }
};
int main()
{
    DynamicArray D1(5);
    DynamicArray D2(10);
    D1.get_ptr()[0] = 3;
    cout << D1.get_ptr()[0] << endl;
    return 0;
}