#include <iostream>
using namespace std;

/*
依赖倒转原则
依赖于抽象(接口)，不要依赖具体的实现(类)，也就是针对接口编程

 

 */

#if 0
class Benz
{
public:
    void run()
    {
        cout << "奔驰启动了" << endl;
    }

};

class BMW
{
public:
    void run()
    {
        cout << "宝马启动了" << endl;
    }
};

class Zhang3
{
public:
    void driveBenz(Benz *b)//zhang3依赖于Benz
    {
        b->run();
    }

    void driveBMW(BMW *b)
    {
        b->run();
    }
};
#endif

//抽象层
class Car
{
public:
    virtual void run() = 0;
};

class Drive
{
public:
    virtual void drive(Car *car) = 0;
};

//实现层
class Zhang3:public Drive
{
public:
    virtual void drive(Car *car)
    {
        cout << "Zhang3 开车了" << endl;
        car->run();
    }
};

class Li4:public Drive
{
public:
    virtual void drive(Car *car)
    {
        cout << "Li4 开车了" << endl;
        car->run();
    }
};

class Benz:public Car
{
public:
    virtual void run()
    {
        cout << "奔驰启动了" << endl;
    }
};

class BMW:public Car
{
public:
    virtual void run()
    {
        cout << "宝马启动了" << endl;
    }
};


//业务
int main()
{
#if 0
    //zhang3开奔驰
    Benz *b = new Benz;
    Zhang3 *z3 = new Zhang3;
    z3->driveBenz(b);


    //zhang3开宝马
    BMW *bw = new BMW;
    z3->driveBMW(bw);
#endif

    Car* benz = new Benz;
    Drive* z3 = new Zhang3;
    z3->drive(benz);

    Car*bmw = new BMW;
    Drive* l4 = new Li4;
    l4->drive(bmw);


    return 0;
}

