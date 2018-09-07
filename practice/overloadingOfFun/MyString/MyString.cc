#include "MyString.h"

MyString::MyString()
{
    this->len = 0;
    this->str = NULL;

}

MyString::~MyString()
{
    if(this->str != NULL)
    {
        cout << this->str << "执行了析构函数" << endl;
        delete[] this->str;
        this->str = NULL;
        this->len = 0;
    }
}

MyString::MyString(int len)//开辟len个长度的字符串，全部设置为0
{
    if(len == 0)
    {
        this->len = 0;
        this->str = new char[len + 1];
        strcpy(this->str, "");
    }
    else
    {
        this->len = 0;
        this->str = new char[len + 1];//开辟长度为len的空间
        memset(this->str, 0, len + 1);//将此空间全部清0
    }

}

MyString::MyString(const MyString& another)//拷贝构造函数
{
     //直接深拷贝
     int len = strlen(another.str);
     this->str = new char[len + 1];
     strcpy(this->str, another.str);
     this->len = len;
}

//MyString str1 = "321321";
//MyString str2("321321");
MyString::MyString(const char*str)//根据str字符串初始化MyString
{
    if(str == NULL)
    {
        this->len = 0;
        this->str = new char[len + 1];
        strcpy(this->str,  "");
    }
    else
    {
        //需要深拷贝
        int len = strlen(str);
        this->str = new char[len + 1];//已经在堆上开辟了内存，实现了深拷贝
        strcpy(this->str, str);//将str的内容拷贝到this->str的堆空间中
    }

}

MyString& MyString::operator=(const MyString& another)//显示的=操作符
{
    if(this->str != NULL)
    {
        delete[] this->str;
        this->str = NULL;
        this->len = 0;
    }

    //进行深拷贝
    int len = strlen(another.str);
    this->str = new char[len + 1];
    strcpy(this->str, another.str);
    
    this->len = another.len;

    return *this;

}

char& MyString::operator[](int index)//重载[]操作符
{
    return this->str[index];
}

bool MyString::operator==(const MyString& another)
{
    if(this->len == another.len)
    {
        for(int i = 0; i < another.len; ++i)
        {
            if(this->str[i] != another.str[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool MyString::operator!=(const MyString& another)
{
    return !(*this == another);

}

bool MyString::operator>(const MyString& another)
{
    int ret = strcmp(this->str, another.str);
    if(ret > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool MyString::operator<(const MyString& another)
{
    int ret = strcmp(this->str, another.str);
    if(ret < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int MyString::getLen()
{
    return this->len;
}

ostream& operator<<(ostream& os, MyString& str)
{
    os << str.str;
    return os;
}

istream& operator>>(istream& is, MyString& str)
{
    char buff[1024] = {0};
    char* temp = buff;
    cout << "请输入一个字符串" << endl;
    cin >> temp;

    //到此步，buf中已经存放了键盘写进的内容
    //深拷贝
    int len = strlen(buff);
    str.str = new char[len + 1];
    str.len = len;
    
    return is;
}
