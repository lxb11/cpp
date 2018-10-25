#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> v1;
	string str;
	while (n--)
	{
		cin >> str;
		v1.push_back(str);
	}

	vector<vector<int> > v2;
	for (unsigned int i = 0; i < v1.size(); ++i)
	{
		vector<int> temp;
		if (v1[i][v1[i].size() - 1] == 'M')
		{
			temp.push_back(1);
			temp.push_back(atoi(v1[i].c_str()));
			v2.push_back(temp);
		}
		else if (v1[i][v1[i].size() - 1] == 'G')
		{
			temp.push_back(2);
			temp.push_back(atoi(v1[i].c_str()));
			v2.push_back(temp);
		}
		else if (v1[i][v1[i].size() - 1] == 'T')
		{
			temp.push_back(3);
			temp.push_back(atoi(v1[i].c_str()));
			v2.push_back(temp);
		}
	}



	sort(v2.begin(), v2.end());
	for (unsigned int i = 0; i < v2.size(); ++i)
	{
		cout << v2[i][1];
		if (v2[i][0] == 1)
			cout << "M";
		else if (v2[i][0] == 2)
			cout << "G"; 
		else if (v2[i][0] == 3)
			cout << "T";
		cout << endl;
	}


	return 0;
}