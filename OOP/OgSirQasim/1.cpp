#include <iostream>
using namespace std;
class Person
{
    int age;

public:
    Person(int age)
    {
        this->age = age;
        cout << "Person constructor ran! \n";
    }
};
class Student : public Person
{
    int a, b;

public:
    Student(int a, int b, int c) : Person(c) /// either this or create a default constructor for Person
    {
        this->a = a;
        this->b = b;
        cout << "Student constructor ran! \n";
    }
};
int main()
{
    Person P1(25);
    Student S1(1, 2, 3);
    return 0;
}