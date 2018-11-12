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

//添加一个梨产品
class Pear:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是凤梨" << endl;
    }
};

//抽象的工厂类
class AbstractFactory
{
public:
    virtual Fruit* createFruit() = 0;//抽象的水果生产器
};

//苹果的工厂
class AppleFactory:public AbstractFactory
{
public:
    virtual Fruit* createFruit()
    {
        return new Apple;
    }
};

//香蕉的工厂
class BananaFactory:public AbstractFactory
{
public:
    virtual Fruit* createFruit()
    {
        return new Banana;
    }
};

//添加一个凤梨工厂
class PearFactory:public AbstractFactory
{
public:
    virtual Fruit* createFruit()
    {
        return new Pear;
    }

};


int main()
{
    //给我来一个香蕉的工厂
    AbstractFactory* bananaFactory = new BananaFactory;
    //给我来一个水果
    Fruit* banana = bananaFactory->createFruit();//只能够生产香蕉
    banana->getName();
    delete  bananaFactory;
    delete  banana;

    AbstractFactory* appleFactory = new AppleFactory;
    Fruit* apple = appleFactory->createFruit();
    apple->getName();
    delete appleFactory;
    delete apple;

    AbstractFactory* pearFactory = new PearFactory;
    Fruit* pear = pearFactory->createFruit();
    pear->getName();



    return 0;
}
