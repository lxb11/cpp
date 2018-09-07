#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()..." << endl;
    }

    ~A()
    {
        cout << "~A()..." << endl;
    }

    void func()
    {
        cout << "a---> func()..." << endl;
    }

};

class MyAutoPtr
{
public:
    //有参数的构造函数，将A的对象的地址，接收过来
    MyAutoPtr(A* ptr)
    {
        this->m_p = ptr;
    }

    ~MyAutoPtr()
    {
        if(this->m_p != NULL)
        {
            delete this->m_p;
        }
    }

    A* operator->()
    {
        return this->m_p;
    }

    A& operator*()
    {
        return *(this->m_p);//*m_p
    }

private:
    A* m_p;

};

void test()
{
    //智能指针不需要我们手动释放delete这个空间
   
    auto_ptr<A> auto_p(new A); //智能指针
    
    auto_p->func();

}

void test2()
{
    MyAutoPtr auto_p(new A);
    //重载 ->
    auto_p->func(); //m_p.func();

    //重载*
    (*auto_p).func();

}

int main()
{
    test();
    test2();
    return 0;
}

