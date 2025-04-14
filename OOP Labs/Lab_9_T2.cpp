#include <iostream>
#include <string>
using namespace std;

template <class Type>
class Stack
{
private:
    Type *elements;
    int topPosition;
    int capacity;

public:
    Stack(int Size = 10)
    {
        capacity = Size;
        elements = new Type[capacity];
        topPosition = -1;
    }

    ~Stack()
    {
        delete[] elements;
    }

    void push(Type value)
    {
        if (topPosition < capacity - 1)
        {
            ++topPosition;
            elements[topPosition] = value;
        }
        else
        {
            cout << "Stack is full!" << endl;
        }
    }

    void pop()
    {
        if (topPosition >= 0)
        {
            topPosition--;
        }
        else
        {
            cout << "Stack is empty!" << endl;
        }
    }

    Type top() const
    {
        if (topPosition >= 0)
            return elements[topPosition];
        else
            ("Stack is empty");
    }

    friend ostream &operator<<(ostream &out, const Stack<Type> &s)
    {
        for (int i = s.topPosition; i >= 0; i--)
        {
            out << s.elements[i] << " ";
        }
        return out;
    }
};

int main()
{
    Stack<int> numStack;
    numStack.push(10);
    numStack.push(20);
    numStack.push(30);
    cout << "Integer Stack: " << numStack << endl;

    Stack<string> wordStack;
    wordStack.push("Hello");
    wordStack.push("World");
    cout << "String Stack: " << wordStack << endl;

    return 0;
}
