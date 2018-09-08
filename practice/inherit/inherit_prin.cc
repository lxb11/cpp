#include <iostream>
using namespace std;

/*
子类对象可以当作父类对象使用
子类对象可以直接赋值给父类对象  初始化
子类对象可以直接初始化父类对象
父类指针可以直接指向子类对象
父类引用可以直接引用子类对象
*/




class Parent
{
public:
    void printP()
    {
        cout << "Parent::printP()" << endl;
    }
};

class Child:public Parent
{
public:
    void printC()
    {
        cout << "Child::printC()" << endl;
    }
};



int main()
{
    Child c; //子类对象
    c.printP();//子类对象可以当作父类对象使用

    Parent p = c;
    //子类对象可以直接赋值给父类对象  初始化
    p.printP();

    Parent *pp = &c;
    pp->printP();



    //Child *cp = &p;//cp->printP, cp->printC





    return 0;
}

