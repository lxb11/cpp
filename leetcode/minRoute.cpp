#include <iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int minRoute(vector<int> route)
{

    return (accumulate(route.begin(), route.end(), 0) - *min_element(route.begin(), route.end()));
}


int main()
{

    int n;
    cin >> n;
    int tmp;
    vector<int> route;

    while(n--)
    {
        cin >> tmp;
        route.push_back(tmp);
    }

    cout << minRoute(route) << endl;

    return 0;
}

