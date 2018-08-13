#include <iostream>

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Test()
{

    int *p = 0;

    std::cout << *p << std::endl;
    int &a = *p;

    std::cout << a << std::endl;
    int b = 2;
    Swap(a, b);
}

int main()
{

    Test();
    std::cout << "Hello world" << std::endl;
    return 0;
}

