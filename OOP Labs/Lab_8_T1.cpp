#include <iostream>
using namespace std;

class Product
{
private:
    string name;
    double price;
    int quantity;

public:
    Product(string name = "", double price = 0.0, int quantity = 0)
    {
        this->price = price;
        this->name = name;
        this->quantity = quantity;
    }

    friend double total_price(int total_items, Product *cart_items);
};

class ShoppingCart
{
private:
    int total_items = 0;
    Product *cart_items = nullptr;

public:
    void getinfo()
    {
        cout << "Enter the number of items: ";
        cin >> total_items;

        cart_items = new Product[total_items];
        if (total_items >= 1)
            cart_items[0] = Product("Honda Civic", 1000, 1);
        if (total_items >= 2)
            cart_items[1] = Product("Toyota Corolla", 150, 2);
        if (total_items >= 3)
            cart_items[2] = Product("Toyota Corolla", 30, 1);
    }

    int getTotalItems() const
    {
        return total_items;
    }

    Product *getCartItems() const
    {
        return cart_items;
    }

    ~ShoppingCart()
    {
        delete[] cart_items;
    }
};

double total_price(int total_items, Product *cart_items)
{
    double total = 0;
    for (int i = 0; i < total_items; i++)
    {
        for (int j = 0; j < cart_items[i].quantity; j++)
        {
            total += 0.9 * cart_items[i].price;
        }
    }
    total *= 1.05;
    return total;
}

int main()
{
    double total = 0.0;
    ShoppingCart cart;
    cart.getinfo();
    total = total_price(cart.getTotalItems(), cart.getCartItems());
    cout << "Total Bill = " << total << endl;
    return 0;
}
