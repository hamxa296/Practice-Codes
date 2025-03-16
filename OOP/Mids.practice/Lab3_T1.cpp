#include <iostream>
using namespace std;
void doublling(int *pt, int &size)
{
    int old_size = size;
    size *= 2;
    for (int i = old_size; i < size; i++)
    {
        pt[i] = i + 2;
    }
}
void display(int *pt, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << pt[i] << endl;
    }
}
int main()
{
    int size;
    int *pt = NULL;
    cout << "Enter the size of the array: \n";
    cin >> size;
    pt = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value at index " << i << " : " << endl;
        cin >> pt[i];
    }
    cout << "Before doubling: " << endl;
    display(pt, size);
    doublling(pt, size);
    cout << "After doubling: " << endl;
    display(pt, size);
    return 0;
}