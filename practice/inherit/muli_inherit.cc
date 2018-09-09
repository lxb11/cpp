#include <iostream>
using namespace std;

//家具
class Furniture
{
public:
    int m;//材质
};

//床类
class Bed:virtual public Furniture
{
public:
    void sleep()
    {
        cout << "sleep" << endl;
    }
};
//如果子类虚继承本类，编译器会将父类中的成员，只拷贝一份

class Sofa:virtual public Furniture
{
public:
    void sit()
    {
        cout << "sit" << endl;
    }
};

class SofaBed:public Bed, public Sofa
{
public:
    void sitAndSleep()
    {
        sleep();
        sit();
    }

};


int main()
{
    Bed b;
    b.sleep();

    cout << "------" << endl;

    Sofa s;
    s.sit();

    cout << "------" << endl;
    SofaBed sb;
    sb.sitAndSleep();

    cout << sb.m << endl;//多继承，如果出现菱形继承，子类继承的父类们，
    //他们会有一个共同的弗雷，就会出现二义性
    return 0;
}

