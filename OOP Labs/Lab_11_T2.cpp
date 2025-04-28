#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Product
{
private:
    int productID;
    string productName;
    int quantity;
    float price;

public:
    void saveProduct(string filename)
    {
        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            stringstream ss;
            ss << productID << "," << productName << "," << quantity << "," << price << endl;
            file << ss.str();
            file.close();
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }

    void addProduct()
    {
        cin.ignore();
        cout << "Enter product name:\n";
        getline(cin, productName);
        cout << "Enter product ID: \n";
        cin >> productID;
        cout << "Enter quantity:\n";
        cin >> quantity;
        cout << "Enter price: \n";
        cin >> price;
    }

    static void listproducts(string filename)
    {
        ifstream file(filename);
        string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }
};

int main()
{
    int option;
    string filename = "products.txt";
    Product P1;

    do
    {
        cout << "1. Add Products \n2. List Products \n3. Exit\n";
        cin >> option;
        switch (option)
        {
        case 1:
            P1.addProduct();
            P1.saveProduct(filename);
            break;
        case 2:
            P1.listproducts(filename);
            break;
        case 3:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid input! \n";
            break;
        }

    } while (option != 3);

    return 0;
}
