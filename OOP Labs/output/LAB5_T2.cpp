#include <iostream>
using namespace std;

class Robot
{
private:
    string *name; // Dynamic string
    double batteryPerc;

public:
    Robot(string name, double batteryPerc)
    {
        this->name = new string(name);
        this->batteryPerc = batteryPerc;
        cout << "Robot " << *this->name << " initialised with battery life: " << batteryPerc << " %\n";
        if (batteryPerc <= 20)
        {
            cout << "Battery is low, recharging automatically! \n";
            batteryPerc = 50;
        }
    }
    ~Robot()
    {
        cout << "Deactivating Robot " << *name << " Memory cleared! \n";
    };
    void task()
    {
        double batteryReq;
        cout << "Enter the energy required for the task: ";
        cin >> batteryReq;

        if (batteryPerc - batteryReq > 0)
        {
            cout << "Task can be performed!" << endl;
            batteryPerc -= batteryReq;
        }
        else
        {
            cout << "Insufficient battery life!" << endl;
        }
        if (batteryPerc <= 20)
        {
            cout << "Battery is low, recharging automatically! \n";
            batteryPerc = 50;
        }
    }

    void Displayinfo()
    {
        cout << "Robot model: " << *name << " | Battery life: " << batteryPerc << " %\n";
    }
};

int main()
{
    string name;
    double batteryPerc;

    cout << "Enter robot model name: ";
    cin >> name;

    cout << "Enter robot battery life: ";
    cin >> batteryPerc;

    Robot robo1(name, batteryPerc);
    robo1.Displayinfo();
    robo1.task();
    robo1.Displayinfo();
    return 0;
}
