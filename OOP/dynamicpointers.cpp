#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int *arr = new int[size]; // DYNAMIC MEMORY ALLOCATION
    // int arr[size]; // USUALLY THIS GIVES ERRORS, BUT IT WORKS HERE
    //size = 9;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the element at index " << i << ": " << endl;
        cin >> arr[i];
    }
    cout << arr[8] << endl;

    cout << "Elements in the array are: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr; // DELETING THE DYNAMIC MEMORY
    return 0;
}
// you are not allowed to change the value of size or loop through the array using a constant greater than sixe, it works over here but its pure luck, so yeah.
// my compiler didnt give me an error, but it might give you an error, so be careful.
// if you want to change the size of the array, you can use the delete[] arr; statement, and then reassign the array with a new size.
// if you dont use the delete[] arr; statement, then the memory will be allocated to the array, and it will not be deallocated, and it will be a memory leak.