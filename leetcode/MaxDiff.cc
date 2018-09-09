#include <iostream>
using namespace std;

int MaxDiff(const int* numbers, unsigned length)
{
    if(numbers == NULL || length < 2)
    {
        return 0;
    }

    int min = numbers[0];
    int maxDiff = numbers[1] - numbers[0];

    for(unsigned int i = 2; i < length; ++i)
    {
        if(min > numbers[i])
        {
            min = numbers[i];
        }

        int currMaxDiff = numbers[i] - min;
        if(currMaxDiff > maxDiff)
        {
            maxDiff = currMaxDiff;
        }
    }
    return maxDiff;
}

void test()
{
    int numbers[] = {9,11,8,5,12,16,14};
    unsigned int length = sizeof(numbers) / sizeof(int);
    cout << MaxDiff(numbers, length) << endl;
}

void test1()
{
    int numbers[] = {9,11};
    unsigned int length = sizeof(numbers) / sizeof(int);
    cout << MaxDiff(numbers, length) << endl;
}

void test2()
{
    int numbers[] = {1,3,5,7,8};
    unsigned int length = sizeof(numbers) / sizeof(int);
    cout << MaxDiff(numbers, length) << endl;
}

void test3()
{
    int numbers[] = {9,7,4,3,1};
    unsigned int length = sizeof(numbers) / sizeof(int);
    cout << MaxDiff(numbers, length) << endl;
}

int main()
{
    test();
    test1();
    test2();
    test3();
    return 0;
}

