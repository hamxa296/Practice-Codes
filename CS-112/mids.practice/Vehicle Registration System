#include <iostream>
using namespace std;
enum vehicle_type
{
    Bike = 1,
    Car,
    Truck
};
union unique_details
{
    int seats;
    int engine_capacity;
    int max_load_capacity;
};
struct Vehicle
{
    int Vehicle_Id;
    string Vehicle_Type;
    int Vehicle_Details;
};
void Display(struct Vehicle veh)
{
    cout << "---------------------------Details for Vehicle Entered--------------------------------";
    cout << "Vehicle ID: " << veh.Vehicle_Id;
    cout << "Vehicle Type: " << veh.Vehicle_Type;
    cout << "Vehicle Unique detail: " << veh.Vehicle_Details;
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
        cout << "Enter the seats of the bike: " << endl;
        cin >> unique.seats;
        cout << "Enter the vehicle ID: " << endl;
        cin >> veh1.Vehicle_Id;
        veh1.Vehicle_Details = unique.seats;
        veh1.Vehicle_Type = Bike;
        break;
    case Truck:
        cout << "Enter the seats of the bike: " << endl;
        cin >> unique.seats;
        cout << "Enter the vehicle ID: " << endl;
        cin >> veh1.Vehicle_Id;
        veh1.Vehicle_Details = unique.seats;
        veh1.Vehicle_Type = Bike;
        break;
    default:
        cout << "Vehicle not identified! :/" << endl;
        break;
    }

    return 0;
}
