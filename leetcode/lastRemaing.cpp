#include <iostream>
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



int main()
{
    return 0;
}

