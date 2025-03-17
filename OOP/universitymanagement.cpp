#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;
    int ID;

public:
    Person(string name, int age, int ID)
    {
        this->name = name;
        this->age = age;
        this->ID = ID;
    }
    virtual void Display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl;
    }
};
class Student : public Person
{
    float GPA;
    Student(string name, int age, int ID, float GPA) : Person(name, age, ID)
    {
        this->GPA = GPA;
    }
    void Display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl;
        cout << "CGPA: " << GPA << endl;
    }
};
class Professor : public Person
{
    bool isPart_time;
    union Salary
    {
        double fixed_salary;
        struct
        {
            int numberOfCourses;
            double perCourse;
        } part_time_details;
    } salary;
    Professor(string name, int age, int ID, float pay) : Person(name, age, ID)
    {
        union Salary;
        cout << "Is the professor part-time?\n1. Press 1 for yes \n2. Press 0 for NO \n";
        cin >> isPart_time;
        if (isPart_time)
        {
            cout << "Enter number of courses: " << endl;
            cin >> salary.part_time_details.numberOfCourses;
            cout << "Enter per course fee: " << endl;
            cin >> salary.part_time_details.perCourse;
            pay = salary.part_time_details.numberOfCourses * salary.part_time_details.perCourse;
        }
        else if (!isPart_time)
        {
            cout << "Enter the fixed salary: " << endl;
            cin >> salary.fixed_salary;
            pay = salary.fixed_salary;
        }
    }
    void Display()
    {
        cout << "Name of Professor: " << name << endl;
        cout << "Age of Professor: " << age << endl;
        cout << "ID of Professor: " << ID << endl;
        if (isPart_time)
            cout << "Salary of professor: " << salary.part_time_details.numberOfCourses * salary.part_time_details.perCourse;
        else
            cout << "Salary of Professor: " << salary.fixed_salary << endl;
    }
    Professor operator+(const Professor &obj)
    {
        float total_salary = 0.0;
        if (!isPart_time)
            total_salary += salary.fixed_salary;
        else
            total_salary += salary.part_time_details.numberOfCourses * salary.part_time_details.perCourse;

        if (!obj.isPart_time)
            total_salary += obj.salary.fixed_salary;
        else
            total_salary += obj.salary.part_time_details.numberOfCourses * obj.salary.part_time_details.perCourse;
        return Professor("combined", 0, 0, total_salary);
    }
};

int main()
{
    Professor p1("Hamza",18, 296, );
    return 0;
}