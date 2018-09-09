#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* arg1, const void* arg2)
{
    return *(int*)arg1 - *(int*)arg2;
}

bool IsContinuous(int* numbers, int length)
{
    if(numbers == NULL || length < 1)
        return false;

    qsort(numbers, length, sizeof(int), compare);

    int numberOfZero = 0;
    int mumberOfGap = 0;

    //统计数组中的间隔数目
    int small = numberOfZero;
    int big = small + 1;
    while(big < length)
    {
        //两个数相等，有对子，不可能是顺子
        if(numbers[small] == numbers[big])
            return false;

        mumberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }

    return (mumberOfGap > numberOfZero) ? false : true;
}

void test1()
{
    cout << "test1()-------" << endl;
    int numbers[] = {2,3,4,1,0};
    int length = sizeof(numbers) / sizeof(int);
    cout << IsContinuous(numbers, length) << endl;
}

void test2()
{
    cout << "test2()-------" << endl;
    int numbers[] = {2,2,4,1,0};
    int length = sizeof(numbers) / sizeof(int);
    cout << IsContinuous(numbers, length) << endl;
}

void test3()
{
    cout << "test3()-------" << endl;
    int numbers[] = {};
    int length = sizeof(numbers) / sizeof(int);
    cout << IsContinuous(numbers, length) << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}

