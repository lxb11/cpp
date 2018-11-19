#include <iostream>
using namespace std;

//抽象手机类
class Phone
{
public:
    virtual void show() = 0;
};

class IPhone:public Phone
{
public:
    virtual void show()
    {
        cout << "秀出了iphone" << endl;
    }
};

class Mi:public Phone
{
public:
    virtual void show()
    {
        cout << "秀出了小米手机" << endl;
    }
};

//写一个抽象装饰器
class Decorate:public Phone
{
public:
    Decorate(Phone* phone)
    {
        this->phone = phone;
    }

    virtual void show() = 0;
protected:
    Phone* phone;//拥有一个 所有手机的父类指针
};

//具体的手贴膜装饰器
class MoDecorate:public Decorate
{
public:
    MoDecorate(Phone* phone):Decorate(phone){}
    virtual void show()
    {
        this->phone->show();//保持原有的show，
        this->mo();//额外添加的方法

    }

    //膜装饰器，可以修饰添加的方法
    void mo()
    {
        cout << "手机有了贴膜" << endl;
    }
};

//皮套的装饰器
class TaoDecorator:public Decorate
{
public:
    TaoDecorator(Phone* phone):Decorate(phone){}
    virtual void show()
    {
        this->phone->show();
        this->tao();
    }

    void tao()
    {
        cout << "手机有了皮套" << endl;
    }
};


int main()
{
    Phone* phone1 = new IPhone;
    phone1->show();
    cout << "---------------" << endl;
    Phone* moPhone1 = new MoDecorate(phone1);
    moPhone1->show();
    //添加皮套
    cout << "--------" << endl;    
    Phone* taoPhone = new TaoDecorator(phone1);
    taoPhone->show();

    cout << "---------" << endl;
    Phone* moTaoPhone = new TaoDecorator(moPhone1);
    moTaoPhone->show();//moPhone.show() + tao() == phone.show() + mo() + tao();



    return 0;
}

