#include <iostream>
#include <list>
using namespace  std;

int LastRemaing(int n, unsigned int m)
{
    if(n < 1 || m < 1)
    {
        return -1;
    }

    int last = 0;
    for(int i = 2; i <= n; ++i)
    {
        last = (last + m) % i;
    }
    return last;
}

int LastRemaingList(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
    {
        return -1;
    }

    list<int> numbers;
    for(unsigned int i = 0; i < n; ++i)
    {
        numbers.push_back(i);
    }

    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1)
    {
        for(unsigned int i = 1; i < m; ++i)
        {
            current++;
            if(current == numbers.end())
                current = numbers.begin();
        }
        
        list<int>::iterator next = ++current;
        if(next == numbers.end())
            next = numbers.begin();

        --current;
        numbers.erase(current);
        current = next;
    }
    return *(current);
}

void test1()
{
    unsigned n = 5;
    unsigned m = 3;
    cout << "test1---------" << endl;
    cout << LastRemaing(n, m) << endl;
    cout << LastRemaingList(n, m) << endl;
}

void test2()
{
    unsigned n = 7;
    unsigned m = 9;
    cout << "test2---------" << endl;
    cout << LastRemaing(n, m) << endl;
    cout << LastRemaingList(n, m) << endl;
}

void test3()
{
    unsigned n = 0;
    unsigned m = 3;
    cout << "test3---------" << endl;
    cout << LastRemaing(n, m) << endl;
    cout << LastRemaingList(n, m) << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}

