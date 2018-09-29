/*************************************************************************
	> File Name: array_practice.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 23时05分50秒
 ************************************************************************/

#include<iostream>
#include<stdexcept>
#include<array>
#include<vector>
#include<algorithm>//sort()
#include<ctime> 
#include<cstdio> //snprintf()
#include<cstdlib> //abort()

using namespace std;


void test_vector(long &value)
{
    cout << "\ntest_vector()....... \n";

    vector<string> c;
    char buf[10];
    clock_t timeStart = clock();

    for (long i = 0; i < value; ++i)
    {
        try
        {
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch(exception& p)
        {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
        cout << "milli-seconds : " << (clock()-timeStart) << endl;
        cout << "vector.max_size()= " << c.max_size() << endl;//1073747823
        cout << "vector.size()= " << c.size() << endl;
        cout << "vector.front()= " << c.front() << endl;
        cout << "vector.back()= " << c.back() << endl;
        cout << "vector.data()= " << c.data() << endl;
        cout << "vector.capacity()= " << c.capacity() << endl << endl;
}

int main()
{
    long a = 1000;
    test_vector(a);
}
