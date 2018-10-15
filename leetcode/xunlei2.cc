#include <vector>
#include <iostream>
using namespace std;

bool isr(int a, int b)
{
    if (a == b)
        return false;
    else if (a == 1 || b == 1)
        return true;
    else
    {
        while (1)
        {
            int t = a % b;
            if (t == 0)
                break;
            else
            {
                a = b;
                b = t;


            }

        }
        if (b > 1)
            return false;
        else
            return true;

    }

}

int main()
{
    int N;
    cin >> N;

    int res = 0;
    long long a, b, c;
    for (a = 1; a <= N; a++)
    {
        for (b = a + 1; b <= N; b++)
        {
            for (c = b + 1; c <= N; c++)
            {
                if (a*a + b*b == c*c)
                {
                    if (isr(a, b) && isr(a, c) && isr(b, c))
                        ++res;

                }

            }

        }

    }

    cout << res;
    return 0;
}




