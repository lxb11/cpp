#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

class Sqr
{
public:
    Sqr(int a)
    {
        this->a = a;
    }

    //想把s对象定义成带有一个参数的函数，求出平方 
    //返回 这个a的平方
    int operator()(int a)
    {
        return a * a;
    }

private:
    int a;
};

//a普通int
//fp --> int(*)(int)
void func(int a, int(*fp)(int))
{
    cout << a << "的平方结果是" << endl;
    cout << fp(a) << endl;

}

int sqr_(int a)
{
    return a * a;
}

class Print
{
public:
    void operator()(int value)
    {
        cout << value << endl;
    }

};

int main()
{

    Sqr s(10);

    //s对象当成一个函数来使用
    //这种写法，就是仿函数，将s对象变成一个函数来使用，编译器认为s是一个函数
    
    cout << s(20) << endl; //s.operator()(20);

    //把一个对象 当成一个回调函数穿进去，就是仿函数的作用

    int b = 20;
    func(b, sqr_);

    vector<int> v1;
    for(int i = 0; i < 10; ++i)
    {
        v1.push_back(i + 10);
    }

    cout << "--------------------" << endl;
    Print pObj;
    for_each(v1.begin(), v1.end(), pObj);

    return 0;
}

