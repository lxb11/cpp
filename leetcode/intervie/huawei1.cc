#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	cin >> str;
	vector<int> v1(26, 0);
	for (int i = 0; i < str.size(); ++i)
	{
		++v1[(int)str[i] - 97];
	}

	vector<int>::iterator pos = max_element(v1.begin(), v1.end());
	int max = *pos;
	int index = pos - v1.begin();

	for (int i = 0; i < str.size(); ++i)
	{
		if (v1[(int)str[i] - 97] == max)
		{
			cout << str[i] << endl;
			cout << max;
			return 0;
		}
	}
}