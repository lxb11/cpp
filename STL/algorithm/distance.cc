#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//distance用法
void test01()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        int index = distance(v.begin(), it);
        cout << v[index] << "  ";
    }
    cout << endl;
}

//for_each修改容器之间的值
void setValue(int& v)
{
    v = v + 100;
}

void print2(int v)
{
    cout << v << "  ";
}

void test02()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), setValue);
    for_each(v.begin(), v.end() , print2);
    cout << endl;
}

int main()
{
    cout << "-----------test01-------------" << endl;
    test01();
    cout << "-----------test02-------------" << endl;
    test02();
    return 0;
}

