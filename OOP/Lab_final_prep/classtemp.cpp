#include <iostream>
using namespace std;
template <typename T>
class stack
{
    int size;
    int current;
    T *element;

public:
    stack(int size)
    {
        this->size = size;
        current = 0;
        element = new T[size];
    }
    void push(T num)
    {
        if (current < size - 1)
        {
            element[current] = num;
            current++;
        }
        else if (current == size)
        {
            cout << "WARNING! Stack Overflow!!!\n";
        }
    }
    void pop()
    {
        if (current == 0)
        {
            cout << "Stack Empty! \n";
        }
        else if (current > 0)
        {
            cout << "popped: " << element[current - 1] << endl;
            current--;
        }
    }
    void top()
    {
        if (current == 0)
        {
            cout << "Stack Empty! \n";
        }
        else if (current > 0)
        {
            cout << "Top: " << element[current - 1] << endl;
        }
    }
    T getMax()
    {
        T max = element[0];
        for (int i = 0; i < current; i++)
        {
            if (max < element[i])
            {
                max = element[i];
            }
        }
        return max;
    }
    bool empty()
    {
        if (current <= 0)
        {
            return true;
        }
        else
            return false;
    }
};
int main()
{
    // stack<int> Mystack(5);
    // Mystack.pop();
    // Mystack.push(10);
    // Mystack.push(20);
    // Mystack.push(30);
    // int max = Mystack.getMax();
    // cout << max << endl;
    // Mystack.pop();
    // Mystack.top();
    stack<string> Mystack(5);
    Mystack.pop();
    Mystack.push("Hello");
    Mystack.push("Hiiii");
    Mystack.push("Heyyy");
    string max = Mystack.getMax();
    cout << max << endl;
    Mystack.pop();
    Mystack.top();
    return 0;
}