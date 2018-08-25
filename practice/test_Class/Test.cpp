#include <iostream>
using  namespace std;

class Test
{
public:

    void init(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    //构造函数,是为了给对象提供初始化而出现的
    //函数名字跟类型是一样的，没有返回值，并且可以重载
    //无参数的构造函数
    Test()
    {
        m_x = 0;
        m_y = 0;
    }

    //带参数的构造函数
    Test(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    //带一个参数的构造函数
    Test(int x)
    {
        m_x = x;
    }

    //拷贝构造函数
    Test(const Test & another)
    {
        m_x = another.m_x;
        m_y = another.m_y;
    }

    //析构函数，对象被销毁时，调用析构函数，无返回值，无参数，不可以重载
    ~Test()
    {
        cout << "析构函数" << endl;
    }

    //等号操作符
    void operator = (const Test &t)
    {
        m_x = t.m_x;
        m_y = t.m_y;
    }

    void printT()
    {
        cout << "x = " << m_x << endl << "y = " << m_y << endl;
    }

private:

    int m_x;
    int m_y;
};

void func(Test t)//Test t = //会调用局部变调的拷贝构造函数
{
    t.printT();

}

int main()
{
    Test t;
    t.init(10, 11);
    t.printT();

    Test t1;//创建一个对象，这个对象会直接调用无参数的构造函数

    Test t2(10, 20);//在创建对象完毕以后，就已经给对象的成员变量初始化了
    
    Test t3(10);

    Test t4 = t3;//调用的是拷贝构造函数

    t1 = t;//调用的是等号操作符
    
    func(t2);//会调用局部变量t的拷贝构造函数

    return 0;
}

