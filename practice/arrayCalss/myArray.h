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

    ~myArray();

private:
    int length;//数组目前的长度
    int *space;//apace是在对上开辟空间的首地址元素


};

