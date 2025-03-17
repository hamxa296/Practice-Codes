// Design an Employee Payroll System where employees can either be salaried or hourly paid.
// Use a union to store either a fixed monthly salary or an hourly wage and hours worked, optimizing memory usage.

// Requirements:

// 	•	Implement a union SalaryDetails with:
// 	•	double monthlySalary; (for salaried employees)
// 	•	struct { double hourlyRate; int hoursWorked; } hourlyDetails; (for hourly employees)
// 	•	Implement a class Employee with:
// 	•	string name;
// 	•	int employeeID;
// 	•	bool isSalaried;
// 	•	SalaryDetails salary;
// 	•	void displaySalary(); (Calculate and display the salary based on employee type.)
// 	•	The program should allow the user to add employees, specify salary details, and display payroll information.
#include <iostream>
using namespace std;
union SalaryDetails
{
    double monthlySalary;
    struct
    {
        double hourly_rate;
        int hours_worked;
    } hourlyDetails;
};
class Employee
{
    string name;
    int employeeID;
    bool isSalaried;
    SalaryDetails Salary;

public:
    Employee()
    {
        cout << "Enter Employee name: " << endl;
        cin >> name;
        cout << "Enter Employee ID: " << endl;
        cin >> employeeID;
        cout << "Is this employee salaried : \nPress 1 if yes \nPress 0 if no" << endl;
        cin >> isSalaried;
        if (isSalaried)
        {
            cout << "Enter Monthly Salary: \n";
            cin >> Salary.monthlySalary;
        }
        else
        {
            cout << "Enter Hourly Rate: \n";
            cin >> Salary.hourlyDetails.hourly_rate;
            cout << "Enter number of hours: \n";
            cin >> Salary.hourlyDetails.hours_worked;
        }
    }
    void displaySalary()
    {
        cout << "Employee name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        if (isSalaried)
        {
            cout << "Monthly Salary = " << Salary.monthlySalary;
        }
        else
        {
            cout << "Hourly Details:\n1. Hourly Rate: " << Salary.hourlyDetails.hourly_rate
                 << "\n2. Hours worked: "
                 << Salary.hourlyDetails.hours_worked << endl;
            cout << "Total salary at the end of the month: " << Salary.hourlyDetails.hourly_rate * Salary.hourlyDetails.hours_worked * 20;
        }
    }
};
int main()
{
    Employee E1;
    E1.displaySalary();

    return 0;
}