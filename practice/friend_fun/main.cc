#include "Point.h"

int main()
{
    Point p1(1, 1);
    Point p2(3, 3);
    cout << PointDistance1(p1, p2) << endl;

    PointManager pp;
    cout << pp.PointDistance(p1, p2) << endl;
    

    return 0;
}

