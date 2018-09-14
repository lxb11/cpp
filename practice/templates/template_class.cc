#include <iostream>
using namespace std;



template <typename T>
class A
{
public:
    A(T a)
    {
        this->a = a;
    }

    void printA()
    {
        cout << "a = " << this->a << endl;
    }

private:
    T a;
};

template <typename T>
void func(A<T>& a)
{
    a.printA();
}

class B:public A<int>
{
public:
    B(int a, int b):A(a)
    {
        this->b = b;
    }

    void printB()
    {
        cout << "b = " << b << endl;
    } 

private:
    int b;

};

template <typename T>
class C:public A<T>
{
public:
    C(T a, T c):A<T>(a)
    {
        this->c = c;
    }

    void printC()
    {
        cout << "c = " << c << endl;
    }
private:
    T c;



};

int main()
{
    A<int> a(10);
    a.printA();

    A<double> a1(100.0);
    a1.printA();


    func<int>(a);


    B b(100, 200);
    b.printB();

    C<int> c(1000, 2000);
    c.printC();

    return 0;
}

