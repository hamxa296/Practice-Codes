#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string studentName;
    int rollNumber;
    float gpa;
    static int usedRollNumbers[100];
    static int count;

public:
    Student(string studentName, int rollNumber, float gpa)
    {
        if (studentName.length() > 15)
        {
            throw length_error("Length Error: Name cannot exceed 15 characters.");
        }
        if (rollNumber <= 0)
        {
            throw runtime_error("Runtime Error: Roll number must be a positive integer.");
        }
        if (gpa < 0.0 || gpa > 4.0)
        {
            throw logic_error("Logic Error: GPA must be between 0.0 and 4.0.");
        }
        for (int i = 0; i < count; i++)
        {
            if (usedRollNumbers[i] == rollNumber)
            {
                throw invalid_argument("Error: Duplicate roll number. Please enter a unique roll number.");
            }
        }

        usedRollNumbers[count++] = rollNumber;
        this->studentName = studentName;
        this->rollNumber = rollNumber;
        this->gpa = gpa;
    }

    friend void printStudentDetails(const Student &student);
};

int Student::usedRollNumbers[100] = {0};
int Student::count = 0;

void printStudentDetails(const Student &student)
{
    cout << "\nStudent Details \n";
    cout << "Name       : " << student.studentName << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "GPA        : " << student.gpa << endl;
    cout << "--------------------\n";
}

int main()
{
    int totalEnrolled = 0;
    string choice;

    do
    {
        try
        {
            string name;
            int roll;
            float gpa;

            
            cout << "\nEnter student name: ";
            cin >> name;
            cout << "Enter roll number: ";
            cin >> roll;

            cout << "Enter GPA: ";
            cin >> gpa;
            
            Student s(name, roll, gpa);
            printStudentDetails(s);
            totalEnrolled++;
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }
        catch (...)
        {
            cout << "An unknown error occurred.\n";
        }

        cout << "\nDo you want to enroll another student? (yes/no): ";
        cin >> choice;
        while (choice != "yes" && choice != "no")
        {
            cout << "Please enter 'yes' or 'no': ";
            cin >> choice;
        }

    } while (choice == "yes");

    cout << "\nTotal students enrolled: " << totalEnrolled << endl;
    cout << "Program completed.\n";
    return 0;
}
