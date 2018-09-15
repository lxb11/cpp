#include <iostream>
using namespace std;


template <typename T>
class A
{
public:
    T value;
    static T a;

};

template <typename T>
T A<T>::a = 0;

int main()
{   
    A<int> a1, a2;
    A<char> b1, b2;

    A<int>::a = 10;
    A<char>::a = 'X';

    cout << "a1:a " << a1.a << endl;//20
    cout << "b1:a " << b1.a << endl;//'X'
    

    cout << "a1:a " << a2.a << endl;//20
    cout << "b1:a " << b2.a << endl;//'X'

    return 0;
}

