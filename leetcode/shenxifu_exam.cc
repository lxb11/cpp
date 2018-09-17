#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int temp;
	vector<int> vec;
	while (n--)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());
	vector<int> result;
	int m;
	cin >> m;
	int i = 0;
	while (m--)
	{
		if (vec.size() % 2 == 1)
		{
			sort(vec.begin(), vec.end());
			result.push_back(vec[vec.size() / 2]);
		}
		cin >> temp;
		vec.push_back(temp);
	
	}
	sort(vec.begin(), vec.end());
	result.push_back(vec[vec.size() / 2]);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}