#include"String_class.h"
#pragma warning(disable:4996)

/*构造函数适用一个字符串数组进行String的初始化，默认的字符串数组为空。
这里的函数定义中不需要再定义参数的默认值，因为在类中已经声明过了。
另外，适用C函数strlen的时候需要注意字符串参数是否为空，对空指针调用strlen会引发内存错误。*/
MyString::MyString(const char *str)
{
	if (str == NULL) 
	{
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else
	{
		length = strlen(str);
		data = new char[length + 1];
		strcpy(data, str);
	}
}

//拷贝构造函数需要进行深复制
MyString::MyString(const MyString &str)
{
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());

}

//析构函数需要进行内存的释放及长度的归零
MyString::~MyString()
{
	delete []data;
	length = 0;
}

//重载字符串赋值运算，这个运算会改变原有字符串的值，为了避免内存泄露，
//这里释放了原先申请的内存再重新申请一块适当大小的内存存放新的字符串
MyString &MyString::operator=(const MyString &str)//重载
{
	if (this == &str)
	{
		return *this;
	}

	delete []data;
	length = str.length;
	data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

int MyString::size() const
{
	return length;
}

const char* MyString::c_str() const
{
	return data;
}