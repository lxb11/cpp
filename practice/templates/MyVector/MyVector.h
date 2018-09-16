#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyVector
{
public:
    friend ostream& operator<<(ostream& os, MyVector<T>& v)
    {
        for(int i = 0; i < v.len; ++i)
        {
            os << v[i] << "  ";
        }
        return os;
    }
    //无参的构造
    MyVector();
    MyVector(int num);
    ~MyVector();
    MyVector(const MyVector& another);

    //重写[]操作符
    T& operator[](int index);
    MyVector& operator=(const MyVector& another);


private:
    int len;
    T* space;

};


template <class T>
MyVector<T>::MyVector()
{
    this->len = 0;
    this->space = NULL;

}

template <class T>
MyVector<T>::MyVector(int num)
{
    if(num > 0)
    {
        this->len = num;
        this->space = new T[num];//在堆上连续开辟sizeof(T)*num

    }

}

template <class T>
MyVector<T>::~MyVector()
{
    if(this->space != NULL)
    {
        delete[] this->space;
        this->len = 0;                                                                       
    }               
}

template <class T>
T& MyVector<T>::operator[](int index)
{
    return this->space[index];
}


template <class T>
MyVector<T>::MyVector(const MyVector& another)
{
    this->len = another.len;
    this->space = new T[this->len];
    //copy数组中每一个元素
    for(int i = 0; i < this->len; ++i)
    {
        this->space[i] = another.space[i];//如果存放对象，那么对象需要深拷贝
    }


}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& another)
{
    if(this->space != NULL)
    {
        delete[] this->space;
        this->space = NULL;
        this->len = 0;
    }

    this->len = another.len;
    this->space = new T[this->len];

    //copy数据
    for(int i = 0; i < this->len; ++i)
    {
        this->space[i] = another.space[i];
    }
    return *this;
}

