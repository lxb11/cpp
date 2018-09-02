#include <iostream>

//不用加减乘除做加法
int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);

    return num1;
}

void test1()
{
    std::cout << Add(2, 4) << std::endl;
}

void test2()
{
    std::cout << Add(-2, -24) << std::endl;
}

void test3()
{
    std::cout << Add(0, 0) << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}

