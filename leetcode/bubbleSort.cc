#include <iostream>
using namespace std;

void bubbleSort(int *data, int length)
{
    if(data == NULL || length < 1)
        return;

    bool flag = false;
    int beginIndex = 0;
    int endIndex = length - 1;
    int lastSwap = 0;
    for(int i = 0; i < length; ++i)
    {
        flag = false;
        if(i % 2 == 0)
        {
            for(int j = beginIndex; j < endIndex; ++j)
            {
                if(data[j] > data[j + 1])
                {
                    swap(data[j], data[j + 1]);
                    flag = true;
                    lastSwap = j;
                }
            }
            endIndex = lastSwap;
        }
        else
        {
            for(int j = endIndex; j > beginIndex; --j)
            {
                if(data[j] < data[j - 1])
                {
                    swap(data[j], data[j - 1]);
                    flag = true;
                    lastSwap = j;
                }
            }
            beginIndex = lastSwap;
        }
        if(flag == false)
            break;
    }
    for(int i = 0; i < length; ++i)
    {
        cout << data[i] << "   ";
    }
    cout << endl;
}

void test()
{
    int data[] = {3,1,5,8,5,3,9};
    int length = sizeof(data) / sizeof(int);
    bubbleSort(data, length);
    for(int i = 0; i < length; ++i)
    {
        cout << data[i] << "   ";
    }
    cout << endl;
}


int main()
{
    test();
    return 0;
}

