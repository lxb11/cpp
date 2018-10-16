#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//merge算法
void print(int v)
{
    cout << v << "  ";
}

void test01()
{
    vector<int> v1, v2, v3; 
    v1.push_back(2);
    v1.push_back(9);
    v1.push_back(3);
    v1.push_back(4);
    sort(v1.begin(), v1.end());

    v2.push_back(5);
    v2.push_back(7);
    v2.push_back(2);
    v2.push_back(0);
    sort(v2.begin(), v2.end());

    v3.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), print);
    cout << endl;
}

//random_shuffle 洗牌 将容器中的元素顺序打乱
void test02()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print);
    cout << endl;

    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), print);
    cout << endl;
}

//reverse
void test03()
{
    vector<int> v;
    for(int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), print);
    cout << endl;

    reverse(v.begin(), v.end());

    for_each(v.begin(), v.end(), print);
    cout << endl;

    
}


int main()
{
    cout << "-----------test01--------------" << endl;
    test01();
    cout << "-----------test02--------------" << endl;
    test02();
    cout << "-----------test03--------------" << endl;
    test03();
    return 0;
}

