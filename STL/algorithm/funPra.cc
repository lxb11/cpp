#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//一元函数对象：函数参数有一个
//二元函数对象：函数参数有两个

//一元谓词：函数参数1个，函数返回值是bool类型，可以作为一个判断式
//            谓词可以使用一个仿函数，也可以是一个回调函数
//二元谓词：函数参数2个，函数返回值是bool类型


//一元函数对象 应用举例: for_each
class print
{
public:
    void operator()(int v)
    {
        cout << v << "  ";
    }   

};

void print1(int v)
{
    cout << v << "  ";
}   

void test0()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i + 10);
    }
    print p;
    for_each(v.begin(), v.end(), p);
    cout << endl;
    for_each(v.begin(), v.end(), print1);
    cout << endl;
}

//一元谓词，应用举例

class mycompare
{
public:
    bool operator()(int v)
    {
        if(v > 7)
            return true;
        else
            return false;
    }
};
void test1()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    
    vector<int>::iterator pos = find_if(v.begin(), v.end(), mycompare());//匿名函数对象
    if(pos == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到" << *pos << endl;
    }
}

//二元函数对象：函数参数有两个 transform
class myplus
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }

};

void test2()
{
    vector<int> v1;
    for(int i = 0; i < 10; ++i)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    for(int i = 0; i < 10; ++i)
    {
        v2.push_back(i);
    }

    vector<int> v3;
    for(int i = 0; i < 10; ++i)
    {
        v3.push_back(i);
    }
    
    for_each(v1.begin(), v1.end(), print1);
    cout << endl;
    for_each(v2.begin(), v2.end(), print1);
    cout << endl;
    for_each(v3.begin(), v3.end(), print1);
    cout << endl;

    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), myplus());//匿名函数对象
    
    cout << "------------------------" << endl;
    for_each(v1.begin(), v1.end(), print1);
    cout << endl;
    for_each(v2.begin(), v2.end(), print1);
    cout << endl;
    for_each(v3.begin(), v3.end(), print1);
    cout << endl;
}

//二元谓词 应用举例: sort
class mycompare3
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void test3()
{
    int num[] = {5,3,4,1,8,1};
    vector<int> v(num, num + sizeof(num) / sizeof(int));
    for_each(v.begin(), v.end(), print1);
    cout << endl;
    mycompare3 l;
    sort(v.begin(), v.end(), l);
    for_each(v.begin(), v.end(), print1);
    cout << endl;

}

int main()
{
    cout << "---------test0----------" << endl;
    test0();
    cout << "---------test1----------" << endl;
    test1();
    cout << "---------test2----------" << endl;
    test2();
    cout << "---------test3----------" << endl;
    test3();
    return 0;
}

