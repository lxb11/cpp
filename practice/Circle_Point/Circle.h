#pragma once
#include "Point.h"

class Circle

{
public:
    Circle() {}
    ~Circle() {}
    
    void setXY(int x, int y);
    void setR(int r);
    bool judgePoint(Point &p);

private:
    int m_x;
    int m_y;
    int m_r;
};

