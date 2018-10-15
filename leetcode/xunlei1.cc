#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<char> dst;

    int count1 = 1;
    unsigned int i;
    for (i = 1; i < str.size(); ++i)
    {
        if (str[i - 1] == str[i])
        {
            ++count1;

        }
        else
        {
            if (count1 == 1)
            {
                dst.push_back(str[i - 1]);

            }
            else
            {
                dst.push_back(str[i - 1]);
                dst.push_back(count1 + '0');

            }
            count1 = 1;

        }

    }
    if (count1 == 1)
    {
        dst.push_back(str[i - 1]);

    }
    else
    {
        dst.push_back(str[i - 1]);
        dst.push_back(count1 + '0');

    }

    for (unsigned int i = 0; i < dst.size(); ++i)
    {
        cout << dst[i];

    }

    return 0;

}

