#include "myArray.h"


myArray::myArray()
{
    this->space = NULL;
    this->length = 0;
}

myArray::myArray(int len)
{
    if(len <= 0)
    {
        this->length = 0;
        return;
    }

    else
    {
        this->length = len;
        this->space = new int[this->length];//在队上开辟了长度为length的连续空间
        cout << "数组的构造函数 myArray::myArray(len)被调用" << endl; 
    }
}

myArray::myArray(const myArray &another)
{
    if(another.length >= 0)
    {
        this->length = another.length;
        this->space = new int[this->length];

        for(int i = 0; i < this->length; ++i)
        {
            this->space[i] = another.space[i];
        }
    }
    cout << "数组的拷贝构造函数 myArray::myArray(len)被调用" << endl; 
}

int myArray::getLen()
{
    return this->length;
}

//index代表要复制的数组的下标，data数据
void myArray::setData(int index, int data)
{
    if(this->space != NULL)
    {
        this->space[index] = data;
    }

}

int myArray::getData(int index)
{
    return this->space[index];
}

myArray::~myArray()
{
    if(this->space != NULL)
       {
       //此时space有空间
       delete []this->space;//释放数组delete[]
       this->length = 0;
       this->space = NULL;
       cout << "myArray::~myArray()被调用" << endl;

       }
}

int& myArray::operator[](int index) const
{
    return this->space[index];
}

myArray& myArray::operator=(const myArray& another)
{
    if(this->space != NULL ||this->length != 0)
    {
        delete []this->space;
        this->space = NULL;
        this->length = 0;
    }

    //进行深拷贝
    if(another.length > 0)
    {
        this->length =another.length;
        this->space = new int[this->length];//在堆上给space开辟内存
    }
    cout << "重载了=运算符" <<endl;
    for(int i = 0; i < this->length; ++i)
    {
        this->space[i] = another.space[i];
    }

    return *this;
}

bool myArray::operator==(const myArray& another)
{
    if(this->length == another.length)
    {
        for(int i = 0; i < this->length; ++i)
        {
            if(this->space[i] != another.space[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool myArray::operator!=(const myArray& another)
{
    return !(*this == another);
}

ostream& operator<<(ostream& os, const myArray& array)
{
    os << "遍历整个数组" << endl;
    for(int i = 0; i < array.length; ++i)
    {
        os << array[i] << endl;//[]参数是非const，修改为const
    }
    return os;
}

istream& operator>>(istream& is, myArray& array)
{
    cout << "请输入" << array.length << "个数" << endl;
    for(int i = 0; i < array.length; ++i)
    {
        is >> array[i];
    }
    return is;
}


