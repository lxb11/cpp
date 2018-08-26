#include <iostream>
#include <cstdlib>
using namespace std;


void test1()
{
    //new能够完成所有malloc的需求
    int *p = new int;//在堆上动态开辟4个字节
    *p = 10;

    if(p == NULL)
    {
        delete p;//delete一个变量
    }
    cout << *p << endl;

    cout << "......" << endl;

    int *array_p = new int[10];
    for(int i = 0; i < 10; ++i)
    {
        array_p[i] = i;
    }
    delete []array_p;
}


class Test
{
public:
    Test()
    {
        m_a = 0;
        m_b = 0;
    }
    Test(int a, int b)
    {
        m_a = a;
        m_b = b;
        cout << "a = " << m_a <<endl << "b = " << m_b << "构造" << endl;
    }

    ~Test()
    {
        cout << "a = " << m_a <<endl << "b = " << m_b << "析构" << endl;
    }

    void printT()
    {
        cout << "a = " << m_a <<endl << "b = " << m_b << endl;
    }

    void setA(int a)
    {
        m_a = a;
    }
    void setB(int b)
    {
        m_b = b;
    }
private:
    int m_a;
    int m_b;

};


void test2()
{
    Test *p = (Test*)malloc(sizeof(Test));//不会调用对象的构造和析构
    p->setA(10);//malloc出来的指针，只能通过承压UN函数来进行初始化
    p->setB(20);
    p->printT();

    if(p != NULL)
    {
        free(p);
    }
}

void test3()
{
    Test *p = new Test(10, 20);//new 可以调用构造函数
    Test *p1 = new Test();//调用无参的构造函数
    
    p->printT();
    p->printT();
    if(p != NULL)
    {
        delete p;
    }
    if(p1 != NULL)
    {
        delete p1;
    }
}

int main()
{
    test2();

    test3();
    return 0;
}

/*
 malloc 和 free 是函数，new和delete操作符；new和free效率高，因为没有函数的压栈传参的消耗。

 
 */
