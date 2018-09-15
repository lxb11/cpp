#include "Complex.h"
#include "Complex.cc"//不能引入cpp

//模板类的 方法的实现不能够用多文件编写
//如果实现多文件的 由于二次编译 真正的视线是在cpp文件中定义的，需要引入cpp头文件

int main()
{
    Complex<int> c1(10, 20);
    c1.printComplex();

    Complex<int> c2(1, 2);

    Complex<int> c3;//调用无参构造
    c3 = c1 + c2;

    c3.printComplex();


    return 0;
}

