#include <iostream>
#include <deque>
#include <vector>
using namespace std;


vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxInWindows;
    if(num.size() >= size >=1)
    {
        deque<int> index;

        for(unsigned int i = 0; i < size; ++i)
        {
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();

            index.push_back(i);
        }

        for(unsigned int i = size; i < num.size(); ++i)
        {
            maxInWindows.push_back(num[index.front()]);

            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            if(!index.empty() && index.front() <= (int)(i - size))
                index.pop_front();

            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }
    return maxInWindows;
}

void test1()
{
    int nums[] = {2,3,4,2,6,2,5,1};
    int length = sizeof(nums) / sizeof(int);
    vector<int> num(nums, nums + length);
    vector<int> result = maxInWindows(num, 3);
    for(unsigned int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << "    ";
    }
    cout << endl;

}

int main()
{
    test1();
    return 0;
}

