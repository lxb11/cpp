#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using  namespace std;


int main() {
    int n ;
    cin >> n;
    vector<int> vec;

    while(n--) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int j;

    for(int i = 2; i < vec.size();i++)
    {
        int sum = accumulate(vec.begin(), vec.begin() + i + 1,0);
        for(j = 0; j <= i; ++j)
        {
            if(sum - vec[j] <= vec[j])
            {
                break;
            }
        }
        if((j - 1) == i)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
