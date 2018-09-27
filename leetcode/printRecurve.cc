#include <iostream>
using namespace std;

void printRecurve(int *a, int len, int k)
{
    if(a == NULL)
        return;

    if(len == k)
    {
        for(int i = 0; i <= len; ++i)
            cout << a[i];
        cout << endl;
    }
    else
    {
        for(int i = k; i <= len; ++i)
        {
            swap(a[i], a[k]);
            printRecurve(a, len, k + 1);
            swap(a[i], a[k]);
        }
    }
}


int main()
{
    int a[] = {1, 2, 3};
    int len = sizeof(a) / sizeof(int) - 1;
    printRecurve(a, len, 0);
    return 0;
}

