#include <iostream>
using namespace std;
class Vehicle
{
protected:
    string name;
    float speed;

public:
    Vehicle(string name, float speed)
    {
        this->name = name;
        this->speed = speed;
    }
    virtual void show_status() const = 0;
    virtual void change_settings(int val)
    {
        cout << "Changing speed to: " << val << endl;
        speed = val;
    }
    friend void print_Vehicle_info(const Vehicle &veh);
};
class Car : public Vehicle
{
    float fuel_capacity;

public:
    Car(string name, float speed, float fuel_capacity) : Vehicle(name, speed)
    {
        this->fuel_capacity = fuel_capacity;
    }
    void show_status() const
    {
        cout << name << endl;
        cout << speed << endl;
        cout << fuel_capacity << endl;
    }
    void change_settings(int val)
    {
        cout << "Changing fuel capacity to: " << val << endl;
        speed = val;
    }
};
class Truck : public Vehicle
{
    float loading_capacity;

public:
    Truck(string name, float speed, float loading_capacity) : Vehicle(name, speed)
    {
        this->loading_capacity = loading_capacity;
    }
    void show_status() const
    {
        cout << name << endl;
        cout << speed << endl;
        cout << loading_capacity << endl;
    }
    void change_settings(int val)
    {
        cout << "Changing loading capacity to: " << val << endl;
        speed = val;
    }
};
class ElectricBike : public Vehicle
{
    float BatteryLevel;

public:
    ElectricBike(string name, float speed, float BatteryLevel) : Vehicle(name, speed)
    {
        this->BatteryLevel = BatteryLevel;
    }
    void show_status() const
    {
        cout << name << endl;
        cout << speed << endl;
        cout << BatteryLevel << endl;
    }
    void change_settings(int val)
    {
        cout << "Changing Battery Level to: " << val << endl;
        speed = val;
    }
};
void print_Vehicle_info(const Vehicle &veh)
{
    cout << veh.name << endl;
    cout << veh.speed << endl;
}
int main()
{
    Car car("civic", 240, 50);
    Truck truck("Hino", 140, 120);
    ElectricBike ebike("Vlektra", 120, 100);
    Vehicle *fleet[5] = {&car, &truck, &ebike};
    fleet[0]->change_settings(50);
    fleet[0]->show_status();
    fleet[1]->change_settings(150);
    fleet[1]->show_status();
    fleet[2]->change_settings(250);
    fleet[2]->show_status();
    print_Vehicle_info(car);
    return 0;
}