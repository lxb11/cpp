#pragma once
#include <iostream>
using namespace std;

class Point;

class PointManager
{
public:
    double PointDistance(Point& p1, Point& p2);

};

class Point
{
public:
    Point(int x, int y);

    void printPoint();

    int getX();
    int getY();
    //Point认为 全局函数（类外部的函数）PointDistance是我的一个哥们，这个函数
    //可以使用我的私有成员
    //friend double PointDistance(Point& p1, Point& p2);
    //写在哪里都可以

    //声明一个其他类成员函数为自己的友元
    friend double PointManager::PointDistance(Point& p1, Point& p2);

private:
    friend double PointDistance1(Point& p1, Point& p2);
    int x;
    int y;

};
