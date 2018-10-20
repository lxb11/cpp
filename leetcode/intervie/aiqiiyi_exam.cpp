#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void)
{
	string a;
	vector<int> vec;
	cin >> a;
	if (a.size() != 6)
	{
		return -1;
	}

	for (int i = 0; i < a.size(); ++i)
	{
		vec.push_back(a[i] - '0');
	}
	int sum1 = vec[0] + vec[1] + vec[2];
	int sum2 = vec[3] + vec[4] + vec[5];

	int cha = abs(sum1 - sum2);
	sort(vec.begin(), vec.begin() + 3);
	sort(vec.begin() + 3, vec.end());

	if (sum1 < sum2)
	{
		if (cha <= (9 - vec[0]))
		{
			cout << 1;
			return 0;
		}
		else if (cha <= ((9 - vec[0]) + (9 - vec[1])))
		{
			cout << 2;
			return 0;
		}
		else
		{
			cout << 3;
			return 0;
		}
	}
	else if (sum1 > sum2)
	{
		if (cha <= (9 - vec[3]))
		{
			cout << 1;
			return 0;
		}
		else if (cha <= ((9 - vec[3]) + (9 - vec[4])))
		{
			cout << 2;
			return 0;
		}
		else
		{
			cout << 3;
			return 0;
		}
	}
	else
	{
		cout << 0;
		return 0;
	}
}