#include <iostream>
#include <cmath>
using namespace std;

class SolidException
{
    string message;

public:
    SolidException(const string &msg) : message(msg) {}

    const string &what() const
    {
        return message;
    }
};

class Solid
{
public:
    virtual double volume() const = 0;
    virtual ~Solid() {}
};

class Cube : public Solid
{
    double side;

public:
    Cube(double s)
    {
        if (s <= 0)
            throw SolidException("Error: Side length must be positive.");
        side = s;
    }

    double volume() const override
    {
        return side * side * side;
    }
};

class Cylinder : public Solid
{
    double radius, height;

public:
    Cylinder(double r, double h)
    {
        if (r <= 0 || h <= 0)
            throw SolidException("Error: Radius and height must be positive.");
        radius = r;
        height = h;
    }

    double volume() const override
    {
        return M_PI * radius * radius * height;
    }
};

int main()
{
    try
    {
        Cube cube(3);
        Cylinder cylinder(2, 5);
        cout << "Cube volume: " << cube.volume() << endl;
        cout << "Cylinder volume: " << cylinder.volume() << endl;

        Cube invalidCube(-1);
    }
    catch (const SolidException &e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        Cylinder invalidCylinder(0, 10);
    }
    catch (const SolidException &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
