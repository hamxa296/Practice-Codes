#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// Function template for swapping two elements (Extra feature)
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Student Base Class
class Student
{
public:
    string name;
    int rollNumber;
    string course;

public:
    Student(string name, int rollNumber, string course)
        : name(name), rollNumber(rollNumber), course(course) {}

    virtual void displayInfo() const = 0; // Pure virtual

    virtual ~Student() {}
};

// Undergrad Derived Class
class Undergrad : public Student
{
public:
    Undergrad(string name, int rollNumber, string course)
        : Student(name, rollNumber, course) {}

    void displayInfo() const override
    {
        cout << "Undergrad Student: " << name << "\n"
             << "Roll No: " << rollNumber << "\n"
             << "Course: " << course << "\n\n";
    }
};

// Grad Derived Class
class Grad : public Student
{
public:
    Grad(string name, int rollNumber, string course)
        : Student(name, rollNumber, course) {}

    void displayInfo() const override
    {
        cout << "Grad Student: " << name << "\n"
             << "Roll No: " << rollNumber << "\n"
             << "Course: " << course << "\n\n";
    }
};

// Template Database Class
template <typename T>
class DataBase
{
private:
    int size;
    int current;
    T *Array;

public:
    DataBase(int size) : size(size), current(0)
    {
        Array = new T[size];
    }

    void Adddata(const T &other)
    {
        if (current >= size)
        {
            throw logic_error("Array size full!\n");
        }
        Array[current++] = other;
    }

    void displayData()
    {
        for (int i = 0; i < current; i++)
        {
            Array[i]->displayInfo();
        }
    }

    void load_infile(const string &filename)
    {
        ofstream ufile(filename);
        if (!ufile)
        {
            throw runtime_error("File cannot be opened\n");
        }
        for (int i = 0; i < current; i++)
        {
            ufile << "Name: " << Array[i]->name
                  << ", Roll No: " << Array[i]->rollNumber
                  << ", Course: " << Array[i]->course << "\n";
        }
        ufile.close();
    }

    ~DataBase()
    {
        cout << "Deleting Database\n";
        delete[] Array;
    }
};

int main()
{
    try
    {
        DataBase<Student *> db(3);

        db.Adddata(new Undergrad("Ali", 101, "CS"));
        db.Adddata(new Grad("Sara", 102, "AI"));
        db.Adddata(new Undergrad("Zain", 103, "EE"));

        cout << "\nDisplaying Data:\n";
        db.displayData();

        cout << "Saving to file...\n";
        db.load_infile("students.txt");
    }
    catch (const logic_error &e)
    {
        cout << "Logic Error: " << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Runtime Error: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "General Exception: " << e.what() << endl;
    }

    return 0;
}
