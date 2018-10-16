#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

//accumulate 
void test01()
{
    vector<int> v;
    for(int i = 0; i <= 100; ++i)
    {
        v.push_back(i);
    }

    int n = accumulate(v.begin(), v.end(), 0);
    cout << n << endl;
}

//fill
struct print
{
    void operator()(int v)
    {
        cout << v << "  ";
    }

};

void test02()
{
    vector<int> v;
    v.resize(10); //开辟10个空间
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), print());
    cout << endl;
}

int main()
{
    cout << "--------------test01-------------" << endl;
    test01();
    cout << "--------------test02-------------" << endl;
    test02();
    return 0;
}

