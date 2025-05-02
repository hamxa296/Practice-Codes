#include <iostream>
using namespace std;
class A
{
public:
 virtual void show()
    {
        cout << "HAHAHHAHHAHAHHHAHAH\n";
    }
};
class B
{
public:
    void show()
    {
        cout << "HAHHHAAAAAAAAAHAHAHAH\n";
    }
};
class C : public A, public B
{
};
int main()
{
    C c1;
    A * ptr = &c1;
    //// if virtual isnt added base class would only use base class methods
    // c1.show();//// two ways to remove this ambguity
    ptr->show();
    c1.A::show();
    c1.B::show();
    ///////OR 
    return 0;
}