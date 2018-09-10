#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void func(int a, int b)
    {
        cout << "Parent:func(int a, int b)..." << endl;
    }

    void func(int a, int b, int c)
    {
        cout << "Parent:func(int a, int b, int c)..." << endl; 
    }
private:
    int a;
};

class Child:public Parent
{
public:
    virtual void func(int a, int b)
    {
        cout << "Child:func(int a, int b)..." << endl; 
    }

    void func(int a, int b, int c)
    {
        cout << "Child:func(int a, int b, int c)..." << endl; 
    }
};

int main()
{
    Child c;
    Parent *p = &c;

    p->func(10, 20);//动态联编

    p->func(10, 20, 30);//静态联编

    cout << sizeof(*p) << endl;//证明了vptr的存在

    return 0;
}

