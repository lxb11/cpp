#include "Point.h"
#include <cmath>


Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::printPoint()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}

//通过全局方式写一个两点之间的距离
//如果发现有一个方式，是全局的不是类自己的成员函数
double PointDistance1(Point& p1, Point& p2)
{
    //int dd_x = p1.getX() - p2.getX();
    //int dd_y = p1.getY() - p2.getY();

    int dd_x = p1.x - p2.x;
    int dd_y = p1.y - p2.y;

    return sqrt(dd_x * dd_x + dd_y * dd_y);
}

double PointManager::PointDistance(Point& p1, Point& p2)
{
    //int dd_x = p1.getX() - p2.getX();
    //int dd_y = p1.getY() - p2.getY();

    int dd_x = p1.x - p2.x;
    int dd_y = p1.y - p2.y;

    return sqrt(dd_x * dd_x + dd_y * dd_y);
}



