#include <iostream>
using namespace std;


class A
{
public:
    A(int a, int b)
    {
        m_a = a;
        m_b = b;
    }

    int getC()
    {
        cout << "C = " << m_c <<endl;
        return m_c;
    }

    static int m_c;//静态成员变量，在类内声明
    //静态成员是对本类共享的

private:
    int m_a;
    int m_b;

};

int A :: m_c = 0;//在类外初始化

int main()
{

    A a(10, 20), a1(11, 22), a2(22, 33);
    a.getC();
    a1.getC();

    A :: m_c = 100;


    a2.getC();


    return 0;
}

