#include <iostream>
using namespace std;

/*
 *合成复用原则
 如果继承和组合都能完成功能的添加，那么优先使用组合（依赖）。

 *
 *
 *
 * */

class Cat
{
public:
    void sleep()
    {
        cout << "小猫睡觉了" << endl;
    }
};

//想给猫添加一个功能，创建一个新的猫，既能睡觉，也能吃东西
class AdvCat:public Cat
{
public:
    void eatAndSleep()
    {
        cout << "吃东西" << endl;
        sleep();
    }
};

//使用组合的方式来来添加小猫的吃东西
//使用组合的方式，降低了AdvCat2和Cat的耦合度，跟Cat的父类没有任何关系，
//只跟cat的sleep方法有关系

class AdvCat2
{
public:
    AdvCat2(Cat *cat)
    {
        this->cat = cat;
    }

    void eatAndSleep()
    {
        cout << "吃东西" << endl;
        cat->sleep();
    }

private:
    Cat *cat;
};



int main()
{
    Cat c;
    c.sleep();

    AdvCat ac;
    ac.eatAndSleep();

    AdvCat2 ac2(&c);
    ac2.eatAndSleep();


    return 0;
}

