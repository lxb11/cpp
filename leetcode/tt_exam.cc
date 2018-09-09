#include<iostream>
#include<vector>
#include<string>
using namespace std;


//头条笔试3——2
int getNum(vector<vector<int> >& people, int i, int j, vector<vector<int> >& reach)
{
    int m = people.size(), n = people[0].size();
    if (i >= m || j >= n || i<0 || j<0)
    {
        return 0;

    }
    else if (people[i][j] == 1 && reach[i][j] == 0)
    {
        reach[i][j] = 1;
        int n1 = getNum(people, i - 1, j, reach) + getNum(people, i + 1, j, reach);
        int n2 = getNum(people, i, j - 1, reach) + getNum(people, i, j + 1, reach);
        return n1 + n2 + 1;

    }
    else
    {
        return 0;

    }

}
void getdata(vector<vector<int> >& people, vector<int>& num, vector<vector<int> >& reach)
{
    int m = people.size(), n = people[0].size();
    for (int i = 0; i<m; i++)
        for (int j = 0; j<n; j++)
        {
            if (people[i][j] == 1 && reach[i][j] == 0)
            {
                int n = getNum(people, i, j, reach);
                num.push_back(n);

            }

        }

}
int main()
{
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << 0;
        return 0;

    }
    vector<vector<int> > depart;
    vector<int> vtemp(n, 0);
    vector<vector<int> > reach(n, vtemp);
    for (int i = 0; i < n; i++)
    {
        vector<int> ptemp;
        int temp;
        for (int j = 0; j < n - 1; j++)
        {
            cin >> temp;
            ptemp.push_back(temp);

        }
        cin >> temp;
        ptemp.push_back(temp);
        depart.push_back(ptemp);

    }
    vector<int>num;
    if (depart.empty())
    {
        cout << 0;
        return 0;

    }
    getdata(depart, num, reach);
    cout << num.size();
    return 0;

}
