#include <iostream>
#include <cstring>
using  namespace std;


class Solution
{
public:
    int lengthOfLongestSubstring(const string& str);
};

int Solution::lengthOfLongestSubstring(const string& str)
{
    int curLength = 0;
    int maxLength = 0;

    int *position = new int[26];
    memset(position, -1, sizeof(position));

    for(int i = 0; i < str.length(); ++i)
    {
        int prevIndex = position[str[i] - 'a'];
        if(prevIndex < 0 || i - prevIndex > curLength)
        {
            ++curLength;
        }
        else
        {
            if(curLength > maxLength)
            {
                maxLength = curLength;
            }

            curLength = i - prevIndex;
        }
        position[str[i] - 'a'] = i;
    }

    if(curLength > maxLength)
    {
        maxLength = curLength;
    }

    delete[] position;
    return maxLength;
}


void test()
{
    string str1 = "sbsjjdlcmmsliq";
    Solution test;
    cout << test.lengthOfLongestSubstring(str1) << endl;
    string str2 = "qqqqqqqqqqqq";
    cout << test.lengthOfLongestSubstring(str2) << endl;
    string str3 = "";
    cout << test.lengthOfLongestSubstring(str3) << endl;
}


int main()
{
    test();
    return 0;
}

