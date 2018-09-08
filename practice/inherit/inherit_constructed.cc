#include <iostream>
using namespace std;

class Parent
{
public:
    Parent(int a)
    {
        cout << "Parent(int a)....." << endl; 
        this->a = a;
    }

    ~Parent()
    {
        cout << "~Parent...." << endl;
    }

    void printA()
    {
        cout << "a = " << this->a << endl;
    }

private:
    int a;
};

class Son:public Parent
{
public:
    Son(int a, int b):Parent(a)
    {
        cout << "Son(int a, int b)...." << endl;
        this->b = b;
    }

    ~Son()
    {
        cout << "~Son()...." << endl;
    }

    void printAB()
    {
        Parent::printA();
        cout << "b = " << this->b << endl;
    }

private:
    int b;
};



int main()
{
    Son s(10, 20);
    s.printAB();
    return 0;
}

