#include <iostream>
using namespace std;
struct person
{
private:
    int id;

public:
    string name;
    int age;
    float height;
    float weight;
    person(int id, string name, int age, float height, float weight)
    {
        cout << "Person constructor called!\n";
        this->id = id;
        this->name = name;
        this->age = age;
        this->height = height;
        this->weight = weight;
    }
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << endl;
        cout << "Weight: " << weight << endl;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId() const
    {
        return id;
    }
    ~person()
    {
        cout << "Destructing person \n";
    }
};
struct student : public person
{
private:
    float GPA;

public:
    string course;
    student(int id, string name, int age, float height, float weight, float GPA, string course) : person(id, name, age, height, weight)
    {
        cout << "Student constructor called!\n";

        this->GPA = GPA;
        this->course = course;
    }
    ~student()
    {
        cout << "Destructing student \n";
    }
    bool operator>(const student &other)
    {
        if (GPA > other.GPA)
        {
            return true;
        }
        else if (other.GPA > GPA)
        {
            return false;
        }
        else
            return false;
    }
};
int main()
{
    student S1(206, "hamza", 18, 170, 75, 3.61, "Ai");
    int id = S1.getId();
    cout << "Id of " << S1.name << ": " << id << endl;
    student S2(306, "ali", 18, 170, 75, 3.72, "Ai");
    if (S1 > S2)
    {
        cout << S1.name << " has higher GPA" << endl;
    }
    else
    {
        cout << S1.name << " doesn't have higher GPA" << endl;
    }
    return 0;
}