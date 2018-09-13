#include <iostream>
using namespace std;


//定义一个函数指针
//C语言决定一个函数类型
//返回值 参数列表



//定义一个函数
int func(int a, int b)
{
    cout << "func 111" << endl;
    return a > b ? a : b;
}


typedef  int (FUNC)(int a, int b);//定义一个函数类型

typedef  int(*FUNC_POINT)(int a, int b);//定义一个函数指针类型


void myFunction(FUNC *fp)
{
    fp(10, 20);
}

void myFunction1(FUNC_POINT fp)
{
    fp(10, 20);
}

void myFunction2(int(*fp)(int a, int b))
{
    cout << "1999年写的架构" << endl;
    cout << "固定业务1" << endl;
    fp(10, 20);
    cout << "固定业务2" << endl;
}


//2005年的一个字函数
int my_new_function(int a, int b)
{
    cout << a << b << endl;
    cout << "2005的函数实现" << endl;
    return 0;
}


int main()
{


    FUNC *p = func;
    FUNC_POINT p2 = func;

    cout << p(10, 20) << endl;;
    cout << (*p)(10, 20) << endl;//以上两种写法等价

    cout << p2(10, 20) << endl;
    cout << (*p2)(10,20) << endl;

    //2015年 调用1999年的架构
    myFunction2(my_new_function);
    


    return 0;
}

