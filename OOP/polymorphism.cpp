#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void start()
    {
        cout << "VEHICLE is starting" << endl;
    }
    virtual void stop()
    {
        cout << "VEHICLE is stopping" << endl;
    }
};

class Car : public Vehicle
{
public:
    void start() override
    {
        cout << "CAR is starting" << endl;
    }
    void stop() override
    {
        cout << "CAR is stopping" << endl;
    }
};

class Bus : public Vehicle
{
public:
    void start() override
    {
        cout << "BUS is starting" << endl;
    }
    void stop() override
    {
        cout << "BUS is stopping" << endl;
    }
};

int main()
{
    Car car;
    Bus bus;

    Vehicle *ptr1 = &car;
    Vehicle *ptr2 = &bus;

    ptr1->start(); // Calls Vehicle's start() method
    ptr2->start(); // Calls Vehicle's start() method

    ptr2->stop();

    return 0;
}