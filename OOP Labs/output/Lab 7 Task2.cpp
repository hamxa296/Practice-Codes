#include <iostream>
using namespace std;
static int trainingboost;
class Animal
{
    int strength;
    int stamina;

public:
    Animal()
    {
        cout << "Enter animal strength: " << endl;
        cin >> strength;
        cout << "Enter animal stamina: " << endl;
        cin >> stamina;
        this->strength = strength;
        this->stamina = stamina;
    }
    void display()
    {
        cout << "Animal Strength: " << strength << endl;
        cout << "Animal Stamina: " << stamina << endl;
    }

    void train()
    {
        stamina += trainingboost;
        strength += trainingboost;
        display();
    }
    void train(Animal &other)
    {
        stamina += other.stamina;
        strength += other.strength;
        display();
    }
    Animal operator+(Animal &other)
    {

        Animal temp;
        temp.stamina = stamina + other.stamina + trainingboost;
        temp.strength = strength + other.strength + trainingboost;
        return temp;
    }
};
int main()
{
    trainingboost = 100;
    Animal lion;
    Animal elephant;
    return 0;
}