#include <iostream>
using namespace std;


//求1+2+3+4+...+n的方法

//1.利用构造函数求解
class Temp
{
public:
    Temp(){++m_N; m_Sum += m_N;}

    static void Reset(){m_N = 0; m_Sum = 0;}
    static unsigned int GetSum(){return m_Sum;}
private:
    static unsigned int m_N;
    static unsigned int m_Sum;
};

unsigned int Temp::m_N = 0;
unsigned int Temp::m_Sum = 0;

unsigned int SumSolution(unsigned int n)
{
    Temp::Reset();

    Temp *a = new Temp[n];
    delete []a;
    a = NULL;

    return Temp::GetSum();

}

//2.利用虚函数求解

class A;
A *Array[2];

class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
private:
    
};

class B: public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n-1) + n;
    }
};

int SumSolution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);

    return value;
}

//3.利用函数指针求解

typedef  unsigned int(*fun)(unsigned int);

unsigned int Solution3Teminator(unsigned int n)
{
    return 0;
}

unsigned int SumSolution3(unsigned int n)
{
    static fun f[2] = {Solution3Teminator, SumSolution3};
    return n + f[!!n](n - 1);
}

//4.利用模板类型求解
template<unsigned int n>struct SumSolution4
{
    enum Value {N = SumSolution4<n - 1>::N + n};
};

template<>struct SumSolution4<1>
{
    enum Value {N = 1};

};

int main()
{

    cout << SumSolution(10) << endl;
    cout << SumSolution2(10) << endl;
    cout << SumSolution3(10) << endl;
    cout << SumSolution4<10>::N << endl;

    return 0;
}

