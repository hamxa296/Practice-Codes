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
    student operator>(const student &other)
    {
        if (GPA > other.GPA)
        {
            return student(getId(), name, age, height, weight, GPA, course);
        }
        else if (other.GPA > GPA)
        {
            return student(other.getId(), other.name, other.age, other.height, other.weight, other.GPA, other.course);
        }
        else
            return student(0, "", 0, 0, 0, 0, "");
    }
};
int main()
{
    student S1(206, "hamza", 18, 170, 75, 3.61, "Ai");
    int id = S1.getId();
    cout << "Id of " << S1.name << ": " << id << endl;
    student S2(306, "ali", 18, 170, 75, 3.72, "Ai");
    student higherS = S2 > S1;
    if (higherS.getId() == 0)
        cout << "GPA is equal!" << endl;
    cout << "Student with higher GPA:" << endl;
    higherS.display();

    return 0;
}