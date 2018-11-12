#include <iostream>
using namespace std;

//1.添加一个日本的工厂和日本的苹果和香蕉（添加一个产品族）
//针对产品族符合开闭原则

//2.添加一个产品种类，鸭梨（添加一个产品等级结构）
//针对产品等级添加不符合开闭原则
//
//3.考虑1,2是否都符合开闭原则
//
//

class Fruit
{
public:
    virtual void getName() = 0;
};

class USAApple:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是美国的苹果" << endl;
    }
};

class USABanana:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是美国的香蕉" << endl;
    }
};

//添加一个美国梨
class USAPear:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是美国的梨" << endl;
    }

};

class ChinaApple:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是中国的苹果" << endl;
    }
};

class ChinaBanana:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是中国的香蕉" << endl;
    }
};

//添加一个中国梨
class ChinaPear:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是中国的梨" << endl;
    }

};

class JapanApple:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是日本的苹果" << endl;
    }
};

class JapanBanana:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是日本的香蕉" << endl;
    }
};

//添加一个中国梨
class JapanPear:public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是日本的梨" << endl;
    }

};

//一个抽象工厂，是面向产品族进行生产的
class AbstractFactory
{
public:
    virtual Fruit* createApple() = 0;
    virtual Fruit* createBanana() = 0;
    //添加一个鸭梨的生产器
    virtual Fruit* createPear() = 0;
};

//美国的具体工厂
class USAFactory:public AbstractFactory
{
public:
    virtual Fruit* createApple()
    {
        return new USAApple;
    }
    virtual Fruit* createBanana()
    {
        return new USABanana;
    }
    //添加一个美国的生产器
    virtual Fruit* createPear()
    {
        return new USAPear;
    }
};

//中国的具体工厂
class ChinaFactory:public AbstractFactory
{
public:
    virtual Fruit* createApple()
    {
        return new ChinaApple;
    }
    virtual Fruit* createBanana()
    {
        return new ChinaBanana;
    }
    //添加一个中国的生产器
    virtual Fruit* createPear()
    {
        return new ChinaPear;
    }
};

//日本的具体工厂
class JapanFactory:public AbstractFactory
{
public:
    virtual Fruit* createApple()
    {
        return new JapanApple;
    }
    virtual Fruit* createBanana()
    {
        return new JapanBanana;
    }
    //添加一个日本的生产器
    virtual Fruit* createPear()
    {
        return new JapanPear;
    }
};

int main()
{
    //想要一个美国的香蕉
    //1.拉一个美国的工厂
    AbstractFactory* usaFactory = new USAFactory;
    //来一个香蕉
    Fruit* usaBanana = usaFactory->createBanana();
    usaBanana->getName();

    
    

    return 0;
}

