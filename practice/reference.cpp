#include <iostream>
using namespace std;


struct TypeA
{
    int *a;
};

struct TypeB
{
    char &a;
};


void test1()
{

    int const re = 10;//常量必须初始化
    int a = 10;
    int b = 20;

    int &c = a;//引用也必须初始化，引用在初始化后，也不能够被改变

    cout << endl;

}


int &getA()//返回值是a的别名                                                             
{
    int a = 1;        
    return a;
}

int &getB()
{
    static int b = 10;
    return b;
}


void test2()
{
    int &r_a = getA();//没有值拷贝动作，禁止,a在栈上函数结束时释放
    int &r_b = getB();//当函数返回值，不是函数内部局部变量时，就可以用引用进行接收

    //cout << r_a << endl;//段错误
    cout << r_b << endl;
    //cout << r_a << endl;
    cout << r_b << endl;

    r_b = 100;

    int value_b = getB();//int &tmp = getB(); int valu_b = tmp;
    cout << getB() << endl;
}


int main()
{
    cout << sizeof(TypeA) << endl;
    cout << sizeof(TypeB) << endl;
    test2();

    return 0;
}

