#include <iostream>
using namespace std;


//静态成员函数只能访问静态成员变量，因为
class Test
{
public:
    Test(int k):m_k(k)
    {

    }

    //在函数后面加const，是修饰this指针 const Test *this
    int getK() const //没一个函数都有一个this指针 getK(Test * const this)
    {
        //this++;
        return m_k;
    }
private:
    int m_k;

};


int main()
{
    Test a1(10);//Test a1(&a1, 10)
    Test a2(11);
    cout << a1.getK() << endl;//a1.get(&a1, 10);
    cout << a2.getK() << endl;



    return 0;
}

