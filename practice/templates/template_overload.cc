#include <iostream>
using namespace std;

//普通函数
void func(int a, int b)
{
    cout << "普通函数" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//模板函数
template<typename T>
void func(T a, T b)
{
    cout << "模板函数" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


//1. 如果没有普通函数，编译器会根据模板函数就行隐事的匹配，如果匹配到模板函数可以调用，调用模板
//2. 编译器匹配函数普通函数优先级大于模板函数
//3. 当普通函数需要隐式转换的时候，如果模板函数能够匹配，那优先使用模板函数
//4. 模板函数是类型的严格匹配
int main()
{
    int aInt = 10;
    int bInt = 20;


    func(aInt, bInt);

    char aChar = 'a';
    char bChar = 'b';
    func(aChar, bChar);

    func(aChar, aInt);



    return 0;
}

