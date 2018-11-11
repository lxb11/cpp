#include <iostream>
using namespace std;

/*
 *开闭原则
类的改动是通过增加代码进行的，而不是修改源代码
对扩展开放，对修改关闭

1.提高可维护性
2.提高了安全性
3.提高了可读性
4.提高了可复用性

 * */


#if 0
class Banker
{
public:
    void save()
    {
        cout << "save money" << endl;
    }
    void pay()
    {
        cout << "pay money" << endl;
    }


    //添加一个办理基金业务
    void fund()
    {
        cout << "办理基金" << endl;
    }
};
#endif 

//抽象类
class AbstractBanker
{
public:
    virtual void work() = 0;//抽象的接口

};

//存款
class SaveBanker:public AbstractBanker
{
public:
    virtual void work()
    {
        cout << "存款" << endl;
    }
};

//支付
class PayBanker:public AbstractBanker
{
public:
    virtual void work()
    {
        cout << "支付" << endl;
    }
};

//添加一个办理基金业务
class FoundBanker:public AbstractBanker
{
public:
    virtual void work()
    {
        cout << "办理基金" << endl;
    }
};


int main()
{
    AbstractBanker *sb = new SaveBanker;
    sb->work();
    delete sb;

    AbstractBanker *pb = new PayBanker;
    sb->work();
    delete pb;

    AbstractBanker *fb = new FoundBanker;
    sb->work();
    delete fb;

    return 0;
}

