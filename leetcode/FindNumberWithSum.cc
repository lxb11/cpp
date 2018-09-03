#include <iostream>
using namespace std;

bool FindNumberswithSum(int data[], int length, int sum, int *num1, int *num2)
{
    if(length < 1 || num1 == NULL || num2 == NULL)
        return false;

    int ahead = length - 1;
    int behind = 0;

    while(ahead > behind)
    {
        int curSum = data[ahead] + data[behind];

        if(curSum == sum)
        {
            *num1 = data[behind];
            *num2 = data[ahead];
            return true;
        }
        else if(curSum < sum)
            ++behind;
        else
            --ahead;
    }
    return false;
}

void test()
{
    cout << "--------test0----------" << endl;
    int data[] = {1,2,4,7,11,15};
    int length = sizeof(data) / sizeof(int);

    int num1 = -1;
    int num2 = -2;

    bool result = FindNumberswithSum(data, length, 15, &num1, &num2);
    if(!result)
    {
        cout << "Not Found" << endl;
        return;
    }

    cout << "num1:" << num1 << endl;
    cout << "num2:" << num2 << endl;
}

void test1()
{
    cout << "--------test1----------" << endl;
    int data[] = {1,2,4,7,11,15};
    int length = sizeof(data) / sizeof(int);

    int num1 = -1;
    int num2 = -2;

    bool result = FindNumberswithSum(data, length, 14, &num1, &num2);
    if(!result)
    {
        cout << "Not Found" << endl;
        return;
    }

    cout << "num1:" << num1 << endl;
    cout << "num2:" << num2 << endl;
}

void test2()
{
    cout << "--------test2----------" << endl;
    int data[] = {};
    int length = sizeof(data) / sizeof(int);

    int num1 = -1;
    int num2 = -2;

    bool result = FindNumberswithSum(data, length, 14, &num1, &num2);
    if(!result)
    {
        cout << "Not Found" << endl;
        return;
    }

    cout << "num1:" << num1 << endl;
    cout << "num2:" << num2 << endl;
}

int main()
{
    test();
    test1();
    test2();
    return 0;
}

