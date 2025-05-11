#include <iostream>
using namespace std;
class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speaks" << endl;
    }
    virtual ~Animal(){};
    
};
class Dog : public Animal
{
    virtual void speak()
    {
        cout << "Woof" << endl;
    }
    //~Dog()override;
};
class Robot : public Animal
{
    virtual void speak()
    {
        cout << "Beep Beep " << endl;
    }
    //~Robot() override;
};
class Robodog : public Dog
{
    void speak()
    {
        cout << "Bark Beep!" << endl;
    }
    //~Robodog() override;
};

int main()
{
    Animal *animal = new Animal;
    Dog dog;
    Robot robot;
    Robodog robodog;
    animal = &dog;
    animal->speak();
    animal = &robot;
    animal->speak();
    animal = &robodog;
    animal->speak();
    delete animal;
    return 0;
}