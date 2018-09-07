#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
public:
    MyString();
    ~MyString();
    MyString(int len);//开辟len个长度的字符串，全部设置为0
    MyString(const MyString& another);//拷贝构造函数
    MyString& operator=(const MyString& another);//显示的=操作符
    MyString(const char*str);//根据str字符串初始化MyString
    char& operator[](int index);//重载[]操作符


    bool operator==(const MyString& another);
    bool operator!=(const MyString& another);
    bool operator>(const MyString& another);
    bool operator<(const MyString& another);
    int getLen();

    friend ostream& operator<<(ostream& os, MyString& str);
    friend istream& operator>>(istream& is, MyString& str);

private:
    char* str;//指向在堆上开辟字符串空间首地址
    int len;//当前字符的长度

};

