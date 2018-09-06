#pragma once
#include <iostream>
using namespace std;

class myArray
{
public:
    //无参的构造函数
    myArray();

    //再给数组初始化的时候，开辟多少个元素空间
    myArray(int len);

    //拷贝构造函数
    myArray(const myArray &another);

    //
    int getLen();

    //index代表要复制的数组的下标，data数据
    void setData(int index, int data);

    int getData(int index);

    //重载操作符[]
    int& operator[](int index) const;
    
    //显示提供一个=
    myArray& operator=(const myArray& another);

    //重载一个==
    bool operator==(const myArray& another);

    //重载一个！=
    bool operator!=(const myArray& another);

    ~myArray();

    friend ostream& operator<<(ostream& os, const myArray& array);
    friend istream& operator>>(istream& is, myArray& array);

private:
    int length;//数组目前的长度
    int *space;//apace是在对上开辟空间的首地址元素
};

ostream& operator<<(ostream& os, const myArray& array);
istream& operator>>(istream& is, myArray& array);

