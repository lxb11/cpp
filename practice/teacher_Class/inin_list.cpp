#include <iostream>
using namespace std;

class ABC
{
public:
    ABC(int a, int b, int c): m_a(a), m_b(b), m_c(c){}

    ABC(const ABC &abc)
    {
        m_a = abc.m_a;
        m_b = abc.m_b;
        m_c = abc.m_c;
    }
    ~ABC()
    {

    }

    void printABC()
    {
        cout << "a = " << m_a << endl;
        cout << "b = " << m_b << endl;
        cout << "c = " << m_c << endl;

    }
private:
    int m_a;
    int m_b;
    int m_c;
};

class ABCD
{
public:
    //初始化例表的顺序与参数顺序无关，与定义成员变量的顺序有关
    ABCD(int a, int b, int c, int d, int m):m_abc(a, b, c),m_m(m)
    {
        m_d = d;
    }

    ABCD(int d, ABC abc, int m):m_abc(abc),m_m(m)
    {
        m_d = d;
    }
    ~ABCD()
    {

    }

    void printABCD()
    {
        m_abc.printABC();
        cout << "d  =" << m_d << endl;
        cout << "const m_m = " << m_m << endl; 
    }
private:
    ABC m_abc;
    int m_d;
    const int m_m; //常量成员变量不能够赋值，只能通过初始化例表初始化

};


int main()
{
    ABC abc_obj1(1, 2, 3);
    ABCD abcd_obj2(40, abc_obj1, 2);

    abcd_obj2.printABCD();


    return 0;
}

