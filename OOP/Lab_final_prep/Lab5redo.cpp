#include <iostream>
using namespace std;
class Robot
{
    int batteryLife;
    string name;

public:
    void recharging()
    {
        if (batteryLife < 20)
        {
            batteryLife = 50;
            cout << "Battery auto recharging! \n";
        }
    }
    ~Robot()
    {
        cout << name << " destructed successfully! " << endl;
    }
    Robot()
    {
        cout << "Enter Robot name: " << endl;
        cin >> name;
        this->name = name;
        cout << "Enter initial battery life: " << endl;
        cin >> batteryLife;
        this->batteryLife = batteryLife;
        cout << "Robot " << name << " initiallised with battery life: " << batteryLife << endl;
        recharging();
    }
    void task_perform()
    {
        int batteryReq;
        cout << "Enter battery req for task: " << endl;
        cin >> batteryReq;
        if (batteryReq > batteryLife)
        {
            recharging();
            cout << "Battery not sufficient for the task!" << endl;
        }
        else
        {
            batteryLife -= batteryReq;
            cout << "Robot performed task by using " << batteryReq << "% battery \n";
            cout << "Remaining battery: " << batteryLife << "% " << endl;
            recharging();
        }
    }
    void displayInfo()
    {
        cout << "Robot: " << name << " | Battery Life: " << batteryLife << "% \n";
    }
};
int main()
{
    Robot robo1;
    robo1.displayInfo();
    robo1.task_perform();
    robo1.displayInfo();
    return 0;
}