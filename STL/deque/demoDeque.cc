#include <iostream>
#include <deque>
using namespace std;


//deque容器初始化
void test0()
{
    deque<int> d1;//默认构造函数
    deque<int> d2(10, 5);//带参数的构造函数
    deque<int> d3(d2.begin(), d2.end());
    deque<int> d4(d3);//拷贝构造

}

//大小操作
void test1()
{
    deque<int> d1(10,3);
    cout << d1.size() << endl;
    if(d1.empty() == true)
        cout << "空！" << endl;
    else
        cout << "不空！" << endl;

    d1.resize(5);
    cout << d1.size() << endl;

}

//deque插入和删除
void test2()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(1);
    d.push_front(2);
    for(deque<int>::iterator it = d.begin(); it != d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    cout << "-------test1---------" << endl;
    test1();
    cout << "-------test2---------" << endl;
    test2();
    return 0;
}

