#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;



class print1
{
public:
    print1():count(0){}

    void operator()(int v)
    {
        count++;
        cout << v << "  ";
    }

    int count;

};

//for_each
void test1()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    print1 p1;
    print1 p2 = for_each(v.begin(), v.end(), p1);//返回值
    cout << endl;
    cout << "count:" << p1.count << endl;
    cout << "count:" << p2.count << endl;
}


//transform

struct myplus
{
    int operator()(int v)
    {
        return v + 100;
    }

};

struct myminus
{
    int operator()(int v1, int v2)
    {
        return v2 - v1;
    }
};

void test2()
{
    vector<int> v1, v2;
    for(int i = 0; i < 10; ++i)
    {
        v1.push_back(i);
    }


    //第一种情况 一个容器中元素经过预算， 把结果放进目标容器中(v2)
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), myplus());
    for_each(v2.begin(), v2.end(), print1());
    cout << endl;

    vector<int> v3, v4, v5;
    for(int i = 0; i < 10; ++i)
    {
        v3.push_back(i);
        v4.push_back(i + 1);
    }

    //第二种方式 一个容器
    v5.resize(v3.size());
    transform(v3.begin(), v3.end(), v4.begin(), v5.begin(), myminus());
    for_each(v5.begin(), v5.end(), print1());
    cout << endl;

    
}



int main()
{
    cout << "----------test1------------" << endl;
    test1();
    cout << "----------test2------------" << endl;
    test2();
    return 0;
}

