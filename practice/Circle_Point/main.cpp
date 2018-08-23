#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
int main()                                                                             
{
    Circle c;
    Point p;

    c.setXY(2, 2); 
    c.setR(4);
    p.setXY(6, 8); 

    if (c.judgePoint(p) == true)
    {   
        cout << "点在圆的内部" << endl;
    }   
    else
    {   
        cout << "点在圆的外部" << endl;
    }   
    return 0;

}
