#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxArrOfVec(vector <int> &vec)
{
	vector<int> temp(vec.size());
	temp[0] = vec[0];
	for (int i = 1; i < (int)vec.size(); i++) {
		if (temp[i - 1] > 0)
			temp[i] = temp[i - 1] + vec[i];
		else
			temp[i] = vec[i];
	}

	return *max_element(temp.begin(), temp.end());

}

int main()
{
	vector<int> vec;
	int temp;
	while (cin >> temp) {
		vec.push_back(temp);
	}

	int max = MaxArrOfVec(vec);
	cout << max;
}

