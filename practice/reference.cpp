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



int main()
{
    char c = 'a';
    b.a = 'w';
    cout << sizeof(TypeA) << endl;
    cout << sizeof(TypeB) << endl;
    cout << c << endl;
    return 0;
}

