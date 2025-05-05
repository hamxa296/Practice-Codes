#include <iostream>
using namespace std;
class Vehicle
{
protected:
    string regNum;
    float rentPerDay;
    int days;

public:
Vehicle(const Vehicle &other){
    regNum=other.regNum;
    rentPerDay=other.rentPerDay;
    days=other.days;
}
    float get_rent()
    {
        return rentPerDay;
    }
    Vehicle(string regNum, float rentPerDay, int days)
    {
        this->regNum = regNum;
        this->rentPerDay = rentPerDay;
        this->days = days;
    }
    virtual float calculateRent() { return 0; };
    virtual void display()
    {
        cout << "Regnum: " << regNum << endl;
        cout << "Rent per day: " << rentPerDay << endl;
        cout << "Number of days: " << days << endl;
    }
    bool operator>(Vehicle &obj)
    {
        return (rentPerDay > obj.get_rent());
    }
    Vehicle operator=(Vehicle &other)
    {
        return Vehicle(other.regNum, other.rentPerDay, other.days);
    }
    friend float totalincome(Vehicle *array[], int numVeh);
    friend class Admin;
    virtual ~Vehicle()
    {
        cout << "Vehicle destructed! \n";
    }
};
class Car : public Vehicle
{
private:
    float fuelCapacity;

public:
    Car(string regNum, float rentPerDay, int days, float fuelCapacity) : Vehicle(regNum, rentPerDay, days)
    {
        this->fuelCapacity = fuelCapacity;
    }
    float calculateRent()
    {
        return (days * rentPerDay);
    }
    void display()
    {
        Vehicle::display();
        cout << "The fuel capacity right now is: " << fuelCapacity << endl;
    }
};
class Motorcycle : public Vehicle
{
private:
    int maxSpeed;

public:
    Motorcycle(string regNum, float rentPerDay, int days, int maxSpeed) : Vehicle(regNum, rentPerDay, days)
    {
        this->maxSpeed = maxSpeed;
    }
    float calculateRent()
    {
        return (days * rentPerDay * 0.9);
    }
    void display()
    {
        Vehicle::display();
        cout << "The Max speed is: " << maxSpeed << endl;
    }
};
class Admin
{
private:
    string Password = "abc123";

public:
    bool authenticate(string passEntered)
    {
        return passEntered == Password;
    }
    void modifyRent(Vehicle *obj)
    {
        string passEntered;
        float newRent;
        cout << "Enter password: " << endl;
        cin >> passEntered;
        if (authenticate(passEntered))
        {
            cout << "Enter new rent: " << endl;
            cin >> newRent;
            obj->rentPerDay = newRent;
            cout << "Rent changed to: " << newRent << endl;
        }
        else
            cout << "Incorrect Password, Access denied! \n";
    }
};
float totalincome(Vehicle *array[], int numVeh)
{
    Admin A1;
    string passEntered;
    cout << "Enter password: " << endl;
    cin >> passEntered;
    if (A1.authenticate(passEntered))
    {
        float totalIncomeGen = 0.0;
        for (int i = 0; i < numVeh; i++)
        {
            totalIncomeGen += array[i]->calculateRent();
        }
        return totalIncomeGen;
    }
    else
        cout << "Incorrect Password, Access denied! \n";
    return 0.0;
}

int main()
{
    Admin A1;

    float totalincomegen;
    Vehicle *car1 = new Car("AAJ605", 5000, 3, 27);
    Vehicle *car2 = new Car("BCD238", 2000, 10, 20);
    Vehicle *M1 = new Motorcycle("hah123", 500, 10, 110);
    Vehicle *M2 = new Motorcycle("hah234", 350, 5, 70);
    car1->display();
    car2->display();
    M1->display();
    M2->display();
    if (car1 > car2)
        cout << "Car 1 has higher rent! \n";
    Vehicle *array[] = {car1, car2, M1, M2};
    totalincomegen = totalincome(array, 4);
    cout << "Total income generated from fleet = " << totalincomegen << endl;
    //A1.modifyRent(car1);
    car1=car2;
    car1->display();
    delete car1;
    delete M1;
    delete car2;
    delete M2;
    return 0;
}