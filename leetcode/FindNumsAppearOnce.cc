#include <iostream>
using namespace std;

//数组中数字出现的次数

bool IsBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}

unsigned int FindFirstBitIs1(int num)
{
    unsigned int indexBit = 0;
    while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
    {
        num = num >> 1;
        ++indexBit;
    }
    return indexBit;
}

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
    if(data == NULL || length < 2)
        return;
    
    int resultXOR = 0;
    for(int i = 0; i < length; ++i)
        resultXOR ^= data[i];

    unsigned int indexOf1 = FindFirstBitIs1(resultXOR);

    *num1 = *num2 = 0;
    for(int j = 0; j < length; ++j)
    {
        if(IsBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}

void test()
{
    int data[] = { 2,4,3,6,3,2,5,5 };
    int length = sizeof(data) / sizeof(int);
    int num1 = -1; 
    int num2 = -1;
    FindNumsAppearOnce(data, length, &num1, &num2);
    cout << num1 << endl;
    cout << num2 << endl;
}

int main()
{
    test();
    return 0;
}

