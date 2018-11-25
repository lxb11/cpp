#include <iostream>
#include <string>
using namespace std;

//销售策略
class AbstractStrategy
{
public:
     //商品具体的销售策略计算方式
     virtual double getPrice(double price) = 0;
};

//策略A
class StrategyA:public AbstractStrategy
{
public:
    virtual double getPrice(double price)
    {
        return 0.8 * price;
    }
private:
};

//策略B 如果商品查过200， 减100
class StrategyB:public AbstractStrategy
{
public:
    virtual double getPrice(double price)
    {
        if(price >= 200)
        {
            price = price - 100;
        }
        return price;
    }
};
//商品
class Item
{
public:
    Item(string name, double price):_name(name), _price(price){}
    //提供一个可以更换策略的方法
    void setStrategy(AbstractStrategy* strategy)
    {
        this->_strategy = strategy;
    }
    double SellPrice()
    {
        return this->_strategy->getPrice(this->_price);
    }
    
private:
    string _name;
    double _price;//商品的价格
    //销售的策略
    AbstractStrategy* _strategy;
};

int main()
{
    Item it("nike鞋", 200);
    AbstractStrategy* sA = new StrategyA;
    AbstractStrategy* sB = new StrategyB;

    cout << "商务商品执行销售策略A 全场8折" << endl;
    it.setStrategy(sA);
    cout << "nike鞋应卖" << it.SellPrice() << endl;

    cout << "商务商品执行销售策略B 全场8折" << endl;
    it.setStrategy(sB);
    cout << "nike鞋应卖" << it.SellPrice() << endl;
    return 0;
}

