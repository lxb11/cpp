#include <iostream>
#include <string>
using namespace std;



//抽象的水果类
class Fruit
{
public:
    virtual void getName() = 0;
};

class Apple:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是苹果" << endl;
    }
};


class Banana:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是香蕉" << endl;
    }
};

//添加一个鸭梨
class Pear:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是鸭梨" << endl;
    }
};

//工厂
class Factory
{
public:
    //水果生产器
    Fruit* createFruit(string kind)
    {
        if(kind == "apple")
        {
            return new Apple;
        }
        else if(kind == "banana")
        {
            return new Banana;
        }
        //添加需要修改代码
        else if(kind == "pear")
        {
            return new Pear;
        }
        return NULL;
    }

};



int main()
{
    //人们是跟工厂打交道
    Factory *f = new Factory;//创建一个工厂
    //给我来个苹果
    Fruit *apple = f->createFruit("apple");

    apple->getName();

    Fruit* banana = f->createFruit("banana");
    banana->getName();

    Fruit* pear = f->createFruit("pear");
    pear->getName();


    delete apple;
    delete banana;
    delete pear;
    delete f;



    return 0;
}

