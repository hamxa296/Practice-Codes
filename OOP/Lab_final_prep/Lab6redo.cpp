#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return fib(n - 1) + fib(n - 2);
}
class NumberAnalyzer
{
protected:
    int num;

public:
    NumberAnalyzer(int num)
    {
        this->num = num;
    }
    void check()
    {
        bool flag = false;
        for (int i = 0; i <= num; i++)
        {
            if (num == fib(i))
            {
                cout << "Number is a Fibonacci number! \n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "Number is not a Fibonacci Number! \n";
    }
};
class NextFibonacci : public NumberAnalyzer
{
public:
    NextFibonacci(int num) : NumberAnalyzer(num)
    {
        return;
    }
    void Next()
    {
        for (int i = 0; i <= num + 1; i++)
        {
            if (fib(i) > num)
            {
                cout << "Next Fibonacci number is: " << fib(i) << endl;
                break;
            }
        }
    }
};
class FibonacciSequence : public NumberAnalyzer
{
public:
    FibonacciSequence(int num) : NumberAnalyzer(num)
    {
        return;
    }

    void Fibonacci_seq()
    {
        for (int i = 0; i <= num; i++)
        {
            cout << fib(i);
        }
    }
};
int main()
{
    NumberAnalyzer NA(5);
    NA.check();
    NextFibonacci NF(5);
    NF.Next();
    FibonacciSequence FB(5);
    FB.Fibonacci_seq();

    return 0;
}