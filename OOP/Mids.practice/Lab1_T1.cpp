#include <iostream>
using namespace std;
struct Author
{
    string name;
    string phone_number;
    string email_address;
};
struct Book
{
    string title;
    Author author;
    int year;
    float price;
};
void input_details(Book *book)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter book " << i + 1 << " title: " << endl;
        getline(cin, book[i].title);
        cout << "Enter Author name: " << endl;
        getline(cin, book[i].author.name);
        cout << "Enter Author phone number: " << endl;
        getline(cin, book[i].author.phone_number);
        cout << "Enter Author email address: " << endl;
        getline(cin, book[i].author.email_address);
        cout << "Enter Year of Publication: " << endl;
        cin >> book[i].year;
        cout << "Enter price: " << endl;
        cin >> book[i].price;
        cin.ignore();
    }
}
void display(Book book[])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Book " << i + 1 << " Title: " << book[i].title << "\n\n";
        cout << "Author name: " << book[i].author.name << endl;
        cout << "Author phone number: " << book[i].author.phone_number << endl;
        cout << "Author email address: " << book[i].author.email_address << endl;
        cout << "Year of Publication: " << book[i].year << endl;
        cout << "Book price: " << book[i].price << "\n\n";
    }
}
int main()
{
    Book book[3];
    input_details(&book[0]);
    display(&book[0]);
    return 0;
}