#include <iostream>
using namespace std;

//图形类
class Shape
{
public:
    //是一个抽象的接口，说明图形是一个又得到面积方法
    virtual double getArea() = 0;//代表一个接口，一个求图形面积的接口

    //
    virtual void print() = 0;
};

//圆类
class Circle:public Shape
{
public:
    Circle(double r)
    {
        this->r = r;
    }

    //重写父类抽象类的纯虚函数
    virtual double getArea()
    {
        return 3.14 * r * r;
    }

    virtual void print()
    {
        cout << "圆的面积:" << endl;
        cout << this->getArea() << endl;
    }
private:
    double r;
};


class Rect:public Shape
{
public:
    Rect(double a)
    {
        this->a = a;
    }

    virtual double getArea()
    {
        return  a * a;
    }

    virtual void print()
    {
        cout << "正方形的面积:" << endl;
        cout << this->getArea() << endl;
    }

private:
    double a;
};

//三角形
class Tri:public Shape
{
public:
    Tri(double a, double h)
    {
        this->a = a;
        this->h = h;
    }
    virtual double getArea()
    {
        return 0.5 * a * h;
    }

    virtual void print()
    {
        cout << "三角形的面积:" << endl;
        cout << this->getArea() << endl;
    }
private:
    double a;
    double h;
};

//一个传递抽象类，指针的架构函数
void printArea(Shape& p)
{
    p.print();
}

int main()
{
    Shape *sp = new Circle(10.0);

    //抽象类的指针就可以调用纯虚函数，接口
    //sp->getArea();//在此处就发生了多态
    //cout<< sp->getArea() << endl;
    
    printArea(*sp);
    
    sp = new Rect(5.0);
    printArea(*sp);

    sp = new Tri(5.0, 10.0);
    printArea(*sp);
    
    return 0;
}

