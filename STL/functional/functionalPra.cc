#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void test1()
{
    plus<int> myplus;
    int ret = myplus(10, 20);
    cout << ret << endl;

    plus<string> myplus2;
    string s1 = "abc";
    string s2 = "defgh";
    string s3 = myplus2(s1, s2);
    cout << s3 << endl;

    cout << plus<int>()(10,222) << endl; //高级写法
}

void print(int v)
{
    cout << v << " ";
}

//tranform
void test2()
{
    vector<int> v1, v2, v3;

    for(int i = 0; i < 10; ++i)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }

    v3.resize(v1.size());

    for_each(v3.begin(), v3.end(), print);
    cout << endl;
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
    for_each(v3.begin(), v3.end(), print);
    cout << endl;
}

int main()
{
    cout << "----------test1-----------" << endl;
    test1();
    cout << "----------test2-----------" << endl;
    test2();
    return 0;
}

