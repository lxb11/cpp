#include <iostream>
using namespace std;


//基类
class Parent
{
public://访问控制权限
    int pub;//对内外均可以
protected:
    int pro;//对内外均不可以
    //儿子可见
private:
    int pri;//对内外均不可以
    //儿子不可见
};

class Child:public Parent //child公有继承
{
    void func()
    {
        this->pro; //可能是私有的和保护的
        //this->pri;//访问不了父类的私有成员
    }

};

//三看原则
//1. 看当前的成员调用实在类的外部还是类的内部
//2. 看儿子的继承方式，是公有继承还是私有继承
//3. 看当前的成员变量在父亲中的访问权限


//1. 基类中的私有成员，在子类中不可访问
//2. 公有继承，在子类中访问权限与父类保持一致
//3. 保护继承，在子类中访问权限变成protected，(private)不变
//4. 私有继承，在子类中访问权限变为私有的

int main()
{
    Parent p;
    p.pub;


    Child c;
    c.pub;


    return 0;
}

