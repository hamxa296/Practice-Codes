#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Student
{
private:
    int id;
    string name;
    float gpa;

public:
   
    void saveToFile(string filename)
    {
        ofstream file(filename, ios::app);  
        if (file.is_open())
        {
            stringstream ss;
            ss << id << "," << name << "," << gpa << endl;
            file << ss.str(); 
            file.close();
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }

    void input()
    {
        cin.ignore();  
        cout << "Enter student name:\n";
        getline(cin, name);
        cout << "Enter Student ID: \n";
        cin >> id;
        cout << "Enter GPA:\n";
        cin >> gpa;
    }

    static void displayAll(string filename)
    {
        ifstream file(filename);
        string line;
        if (file.is_open())
        {
            while (getline(file, line))  
            {
                cout << line << endl;  
            }
            file.close();
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }
};

int main()
{
    int option;
    string filename = "students.txt";  
    Student S1;

    do
    {
        cout << "1. Add Student \n2. Display All Students \n3. Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            S1.input();
            S1.saveToFile(filename);
            break;
        case 2:
            S1.displayAll(filename);
            break;
        case 3:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid input! \n";
            break;
        }

    } while (option != 3);

    return 0;
}
