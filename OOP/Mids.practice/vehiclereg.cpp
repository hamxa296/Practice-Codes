#include <iostream>
using namespace std;

enum vehicle_type
{
    Bike = 1,
    Car,
    Truck
};
string getvehtype(vehicle_type vt);
union unique_details
{
    int seats;
    int engine_capacity;
    int max_load_capacity;
};
struct Vehicle
{
    int Vehicle_Id;
    vehicle_type Vehicle_Type;
    int Vehicle_Details;
};
void Display(struct Vehicle veh)
{
    cout << "-------------Details for Vehicle Entered-------------------\n\n";
    cout << "Vehicle ID: " << veh.Vehicle_Id << endl;
    cout << "Vehicle Type: " << getvehtype(veh.Vehicle_Type) << endl;
    cout << "Vehicle Unique detail: " << veh.Vehicle_Details << endl;
}
string getvehtype(vehicle_type vt)
{
    switch (vt)
    {
    case Bike:
        return "Bike";
        break;
    case Car:
        return "Car";
        break;
    case Truck:
        return "Truck";
        break;

    default:
        return "Vehicle type not identifed! ";
        break;
    }
}
int main()
{
    Vehicle veh1;
    unique_details unique;
    int vehicletype;
    cout << "Enter the type of vehicle:\n1 for bike\n2 for car\n3 for truck\n";
    cin >> vehicletype;
    switch (vehicletype)
    {
    case Bike:
        cout << "Enter the seats of the bike: " << endl;
        cin >> unique.seats;
        cout << "Enter the vehicle ID: " << endl;
        cin >> veh1.Vehicle_Id;
        veh1.Vehicle_Details = unique.seats;
        veh1.Vehicle_Type = Bike;
        break;
    case Car:
        cout << "Enter the engine capacity of the car: " << endl;
        cin >> unique.engine_capacity;
        cout << "Enter the vehicle ID: " << endl;
        cin >> veh1.Vehicle_Id;
        veh1.Vehicle_Details = unique.seats;
        veh1.Vehicle_Type = Car;
        break;
    case Truck:
        cout << "Enter the load capacity of the truck: " << endl;
        cin >> unique.max_load_capacity;
        cout << "Enter the vehicle ID: " << endl;
        cin >> veh1.Vehicle_Id;
        veh1.Vehicle_Details = unique.seats;
        veh1.Vehicle_Type = Truck;
        break;
    default:
        cout << "Vehicle not identified! :/" << endl;
        break;
    }
    Display(veh1);
    return 0;
}
