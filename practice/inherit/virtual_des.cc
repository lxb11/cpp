#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()........." << endl;
        this->p = new char[64];//给p开辟一个空间
        memset(p, 0, 64);
        strcpy(p, "A string");
    }

    virtual ~A()
    {
        cout << "~A()...." << endl;
        if(p != NULL)
        {
            delete[] p;
            p = NULL;
        }
    }

    virtual void print()
    {
        cout << "virtual A print()" << endl;
    }
private:
    char* p;
};

class B:public A
{
public:
    B()
    {
        cout << "B()........." << endl;
        this->p = new char[64];//给p开辟一个空间
        memset(p, 0, 64);
        strcpy(p, "A string");
    }

    virtual ~B()
    {
        cout << "~B()...." << endl;
        if(p != NULL)
        {
            delete[] p;
            p = NULL;
        }
    }
    
    virtual void print()
    {
        cout << "virtual B print()" << endl;
    }
private:
    char* p;
};

class C:public B
{
public:
    C()
    {
        cout << "C()........." << endl;
        this->p = new char[64];//给p开辟一个空间
        memset(p, 0, 64);
        strcpy(p, "A string");
    }

    virtual ~C()
    {
        cout << "~C()...." << endl;
        if(p != NULL)
        {
            delete[] p;
            p = NULL;
        }
    }

    virtual void print()
    {
        cout << "virtual C print()" << endl;
    }
private:
    char* p;
};

void func(A* p)
{
    p->print();
    delete p;
    //如果类的析构函数加上了virtual delete就会发生多态，delete 就会调用C类的析构函数
    //依次析构
}

int main()
{
    C *cp = new C;
    cp->print();//cp 的函数
    delete cp;

    cout << "----------------------" << endl;

    C *cp1 = new C;
    func(cp1);
    return 0;
}

