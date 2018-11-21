#include <iostream>
using namespace std;

//抽象的制作饮料方法
class MakeDrink
{
public:
    //1. 把水煮开
    void boil()
    {
        cout << "把水煮开" << endl;
    }
    //2. 冲某物
    virtual void brew() = 0;
    //3. 从大杯倒入小杯
    void putInCup()
    {
        cout << "把冲泡好的饮料倒入小杯" << endl;
    }
    //4. 加一些酌料
    virtual void addThing() = 0;

    //钩子函数 hook
    virtual bool CustomWantAddThings()
    {
        return true;
    }

    //业务逻辑的统一模板
    void make()
    {
        boil();
        brew();
        putInCup();
        if(CustomWantAddThings())
        {
            addThing();
        }
    }

private:
};

//制作咖啡
class MakeCoffee:public MakeDrink
{
public:
    MakeCoffee(bool isAdd)
    {
        this->isAdd = isAdd;
    }
    //2. 冲某物
    virtual void brew()
    {
        cout << "冲泡咖啡豆" << endl;
    }
    //4. 加一些酌料
    virtual void addThing()
    {
        cout << "加入牛奶和糖" << endl;
    }
    virtual bool CustomWantAddThings()
    {
        return this->isAdd;
    }
private:
    bool isAdd;
};

//冲泡茶叶
class MakeTea:public MakeDrink
{
public:
    MakeTea(bool isAdd)
    {
        this->isAdd = isAdd;
    }
    //2. 冲某物
    virtual void brew()
    {
        cout << "冲茶叶" << endl;
    }
    //4. 加一些酌料
    virtual void addThing()
    {
        cout << "加入柠檬" << endl;
    }
    virtual bool CustomWantAddThings()
    {
        return this->isAdd;
    }
private:
    bool isAdd;
};

int main()
{
    MakeDrink* makeCoffee = new MakeCoffee(false);
    makeCoffee->make();

    cout << "---------------------------" << endl;
    MakeDrink* makeTea = new MakeTea(true);
    makeTea->make();

    return 0;
}

