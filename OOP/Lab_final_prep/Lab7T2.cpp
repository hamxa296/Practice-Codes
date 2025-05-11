#include <iostream>
using namespace std;
class Animal
{
    int strength;
    int stamina;

public:
    Animal(int strength, int stamina)
    {
        this->strength = strength;
        this->stamina = stamina;
    }
    void train(int Boost)
    {
        strength += Boost;
        stamina += Boost;
    }
    void combine(Animal &other)
    {
        stamina = other.stamina + stamina;
        strength = other.strength + strength;
    }
    Animal operator+(Animal &other)
    {
        return Animal(strength + other.strength, stamina + other.stamina);
    }
    void display()
    {
        cout << strength << endl;
        cout << stamina << endl;
    }
};
int main()
{
    static int Boost = 20;
    Animal Elephant(70, 25);
    Animal Lion(65, 60);
    Lion.train(Boost);
    Elephant.train(Boost);
    Lion.display();
    Elephant.display();
    Lion.combine(Elephant);
    Lion.display();
    Lion = Lion + Elephant;
    Lion.display();

    return 0;
}