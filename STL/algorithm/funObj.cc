#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


//bind1st bind2nd   绑定适配器

//第一步 需要你自定义函数对象继承父类， binary_function  unary_function

class print:public binary_function<int, int, void>
{
public:
    void operator()(int v,int v2) const
    {
        if(v > v2)
            cout << v << "  ";
    }


};

void test1()
{
    vector<int> vec;
    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i + 10);
    }

    print p;
    for_each(vec.begin(), vec.end(), bind1st(p, 15));
    cout << endl;

    for_each(vec.begin(), vec.end(), bind2nd(p, 15));
    cout << endl;

    //bind1st bind2nd 绑定适配器， 调用绑定适配器， 统统变成一元函数对象
}

//not1 not2 取反翻适配器

struct mycompare2:public unary_function<int, bool>
{
    bool operator()(int v) const
    {
        return v > 5;
    }

};

class print1
{
public:
    void operator()(int v)
    {
        cout << v << "  ";
    }
};

void test2()
{
    vector<int> vec;
    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    vector<int>::iterator pos = find_if(vec.begin(),  vec.end(), mycompare2());//匿名对象
    if(pos != vec.end())
    {
        cout << "找到：" << *pos << endl;
    }
    else
    {
        cout << "没找到：" << endl;
    }

    mycompare2 myp2;
    pos = find_if(vec.begin(),  vec.end(), not1(myp2));
    if(pos != vec.end())
    {
        cout << "找到：" << *pos << endl;
    }
    else
    {
        cout << "没找到：" << endl;
    }

    //sort算法
    sort(vec.begin(), vec.end(), greater<int>());
    for_each(vec.begin(), vec.end(), print1());
    cout << endl;

    sort(vec.begin(), vec.end(), not2(greater<int>()));
    for_each(vec.begin(), vec.end(), print1());
    cout << endl;
}


int main()
{
    cout << "----------test1-------------" << endl;
    test1();
    cout << "----------test2-------------" << endl;
    test2();
    return 0;
}

