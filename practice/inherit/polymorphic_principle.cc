#include <iostream>
using namespace std;


//不要在构造函数中调用成员函数
class Parent
{
public:
    Parent(int a)
    {
        this->a = a;
    }

    virtual void func()
    {
        cout << "Parent:func(int a, int b)..." << endl;
        cout << "a = " << a << endl;
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
    Child(int a, int b):Parent(a)
    {
        //在此处之前，是构造弗雷德内存空间，此时child还没有构造完毕，
        //vptr指针此时只想的是父类的虚函数表
        this->b = b;
    }

    virtual void func()
    {
        cout << "Child:func(int a, int b)..." << endl; 
        cout << "b = " << b << endl;
    }

    void func(int a, int b, int c)
    {
        cout << "Child:func(int a, int b, int c)..." << endl; 
    }
private:
    int a;
    int b;
};

int main()
{
    /*Child c(10, 20);
    Parent *p = &c;

    p->func();//动态联编

    p->func(10, 20, 30);//静态联编

    cout << sizeof(*p) << endl;//证明了vptr的存在
    


    Parent *p1 = new Child(100, 200);
    p1->func();
*/
    Child array[] = {Child(10, 20), Child(11, 22), Child(12, 33)};
    Child *cp = &array[0];
    Parent *pp = &array[0];

    cp->func();
    pp->func();

    cp++;
    pp++;
    
    //父类与子类的步长不一致
    cp->func();
    pp->func();


    return 0;
}

