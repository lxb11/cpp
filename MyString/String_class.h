#ifndef _STRING_CLASS_
#define _STRING_CLASS_
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(const char *str = NULL);//通用构造函数
	MyString(const MyString &str);//拷贝构造函数
	~MyString();//析构函数
	MyString& operator=(const MyString &str);//重载=

	int size() const; //获取长度
	const char *c_str() const;//获取C字符串长度

private:
	char *data;
	int length;
};

#endif // !String_class



