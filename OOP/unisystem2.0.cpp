#include <iostream>
using namespace std;

// Base Class: Person
class Person
{
protected:
    string name;
    int age;
    int ID;

public:
    // Constructor
    Person(string name, int age, int ID)
    {
        this->name = name;
        this->age = age;
        this->ID = ID;
    }

    // Virtual Display Function (for polymorphism)
    virtual void Display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl;
    }
};

// Derived Class: Student
class Student : public Person
{
    float GPA;

public:
    // Constructor (Needs to be public!)
    Student(string name, int age, int ID, float GPA) : Person(name, age, ID)
    {
        this->GPA = GPA;
    }

    // Override Display Function
    void Display() override
    {
        Person::Display();
        cout << "CGPA: " << GPA << endl;
    }
};

// Derived Class: Professor
class Professor : public Person
{
    bool isPart_time;

    // Union for Salary
    union Salary
    {
        double fixed_salary;
        struct
        {
            int numberOfCourses;
            double perCourse;
        } part_time_details;
    } salary;

public:
    // Constructor
    Professor(string name, int age, int ID, float pay) : Person(name, age, ID)
    {
        cout << "Is the professor part-time?\n1. Press 1 for Yes\n2. Press 0 for No: ";
        cin >> isPart_time;

        if (isPart_time)
        {
            cout << "Enter number of courses: ";
            cin >> salary.part_time_details.numberOfCourses;
            cout << "Enter per course fee: ";
            cin >> salary.part_time_details.perCourse;

            pay = salary.part_time_details.numberOfCourses * salary.part_time_details.perCourse;
        }
        else
        {
            cout << "Enter the fixed salary: ";
            cin >> salary.fixed_salary;
            pay = salary.fixed_salary;
        }
    }

    // Override Display Function
    void Display() override
    {
        cout << "\nProfessor Information:\n";
        Person::Display();
        if (isPart_time)
        {
            cout << "Salary of Professor: "
                 << salary.part_time_details.numberOfCourses * salary.part_time_details.perCourse
                 << endl;
        }
        else
        {
            cout << "Salary of Professor: " << salary.fixed_salary << endl;
        }
    }

    // Operator + Overload (to combine salaries)
    Professor operator+(const Professor &obj)
    {
        float total_salary = 0.0;

        // Add salary of current object
        if (isPart_time)
        {
            total_salary += salary.part_time_details.numberOfCourses * salary.part_time_details.perCourse;
        }
        else
        {
            total_salary += salary.fixed_salary;
        }

        // Add salary of passed object
        if (obj.isPart_time)
        {
            total_salary += obj.salary.part_time_details.numberOfCourses * obj.salary.part_time_details.perCourse;
        }
        else
        {
            total_salary += obj.salary.fixed_salary;
        }

        // Return a new Professor object with the combined salary
        return Professor("Combined", 0, 0, total_salary);
    }
};

// Main Function
int main()
{
    Student obj("hamza", 18, 20, 3.99);
    Person *ptr = &obj;
    ptr->Display();
    // Create two Professor objects
    //Professor p1("Hamza", 35, 101, 0);
    //Professor p2("Ali", 40, 102, 0);

    // Display Professors
    //p1.Display();
    //p2.Display();

    // Combine their salaries
    //Professor combined = p1 + p2;
    cout << "\nAfter Combining Salaries:\n";
    //combined.Display();

    return 0;
}
