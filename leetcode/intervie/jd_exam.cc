#include <iostream>
#include <vector>
using namespace std;


//京东笔试第二题
class group {
public:
    group(int a, int b, int c) : a_(a), b_(b), c_(c) {}
    bool operator < (const group& other) {
        if (this->a_ < other.a_)
            if (this->b_ < other.b_)
                if (this->c_ < other.c_)
                    return true;
                else
                    return false;
            else
                return false;
        else
            return false;

    }
    int a_;
    int b_;
    int c_;

};

int main() {
    vector<group> group_vec;
    int n;
    cin >> n;
    int a;
    int b;
    int c;
    while (n--)
    {
        cin >> a >> b >> c;
        group_vec.push_back(group(a, b, c));

    }

    int count = 0;
    for (unsigned int i = 0; i < group_vec.size(); ++i)
    {
        for (unsigned j = 0; j < group_vec.size(); ++j)
        {
            if (group_vec[i] < group_vec[j])
            {
                ++count;
                break;

            }

        }

    }
    cout << count;

}


