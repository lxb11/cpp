#pragma once
#include <iostream>
using namespace std;


template <class T>
class Complex
{
public:
    Complex();
    Complex(T a, T b);
    ~Complex();
    void printComplex();
    Complex operator+(Complex& another);
    Complex operator-(Complex& another);

private:
    T a;
    T b;

};

