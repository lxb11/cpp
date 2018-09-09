#include <iostream>
using namespace std;

class Parent
{
public:
    Parent(int a)
    {
        this->a = a;
    }

    virtual void print()//给一个成员函数定义为虚函数
    {
        cout << "Parent::print(): a = " << this->a << endl;
    }
private:
    int a;
};

class Child:public Parent
{
public:
    Child(int a, int b):Parent(a)
    {
        this->b = b;
    }

    //重定义发生在子类与父类之间
    //当子类重写父类的成员函数，如果父类中的这个函数不是虚函数，是函数的重定义
    //如果子类重写父类的成员函数，如果父类中的这个函数是 虚函数，这是函数的重写
    virtual void print()//重写时建议写上 virtual ----多态
    {
        cout << "Child:print() b = " << this->b << endl;
    }
    
private:
    int b;
};

//可以用现在写的函数调用未来的函数------多态
void myPrintFunc(Parent& p)
{
    p.print();
}

int main()
{
    Child c(10, 20);
    c.print();
    
    Parent p(100);
    p.print();

    myPrintFunc(p);
    cout << "-----------------" << endl;
    myPrintFunc(c);//希望调用子类的print()
    //编译器不管你传来的是父类还是子类，都会给你调用父类
    //便一起做了一个安全的举措，即使你传递的是子类
    //编译器也会调用父类的print(),他能够安全的保证父类的print()函数一定是存在的
    //没有冒险去调用子类的print()
    

    return 0;
}

