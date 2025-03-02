#include <iostream>
using namespace std;
class Employee
{
private:
    string name;
    string company;
    string designation;
    int age;

public: // CONTRUCTOR ALLOWS US TO ACCESS PRIVATE MEMBERS
    Employee()
    {
        cout << "Enter your name: " << endl;
        cin >> name;
        cout << "Enter company name: " << endl;
        cin >> company;
        cout << "Enter designation: " << endl;
        cin >> designation;
        cout << "Enter age: " << endl;
        cin >> age;
    }
    void introduceyourself()
    {
        cout << "Hello, my name is " << name << endl;
        cout << "I work at " << company << endl;
        cout << "I am a " << designation << endl;
        cout << "I am " << age << " years old" << endl;
    }
};
int main()
{
    // Employee emp1 = Employee("John", "ABC", "Software Engineer", 25); // 2 ways to write this
    // Employee emp2("John", "ABC", "Software Engineer", 25);
    //
    Employee E1;
    E1.introduceyourself();
    return 0;
}