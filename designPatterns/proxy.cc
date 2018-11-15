#include <iostream>
#include <string>
using namespace std;

//商品
class Item
{
public:
    Item(string kind, bool fact)
    {
        this->kind = kind;
        this->fact = fact;
    }
    string getKind()
    {
        return this->kind;
    }
    bool getFact()
    {
        return this->fact;
    }
private:
    string kind;//商品的种类
    bool fact;//商品的真假
};

//抽象的购物方式
class Shopping
{
public:
    virtual void buy(Item* it) = 0;
private:


};

//韩国购物
class KoreaShopping:public Shopping
{
public:
    virtual void buy(Item* it)
    {
        cout << "去韩国买了" << it->getKind() << endl;
    }
};

//美国购物
class USAShopping:public Shopping
{
public:
    virtual void buy(Item* it)
    {
        cout << "去美国买了" << it->getKind() << endl;
    }

};

//海外代理
class OverseasProxy:public Shopping
{
public:
    OverseasProxy(Shopping* shopping)
    {
        this->shopping = shopping;
    }


    virtual void buy(Item* it)
    {
        //1. 辨别商品的真假
        //2. 进行购买（）
        //3. 通过海关安检，带回祖国
        //...
        if(it->getFact() == true)
        {
            cout << "发现正品要购物了" << endl;
            shopping->buy(it);
            cout << "通过海光安检，带回祖国" << endl;
        }
        else
        {
            cout << "发现假货，不会购买" << endl;
        }
        this->shopping->buy(it);
        //...
    }
private:
    Shopping* shopping;//有一个购物方式

};

int main()
{
    //1. 辨别商品的真假
    //2. 进行购买（）
    //3. 通过海关安检，带回祖国
    
    Item it("nike鞋", true);

#if 0
    //想去韩国买一个nike鞋子
    Shopping* koreaShopping = new KoreaShopping;
    //辨别商品真伪
    if(it.getFact() == true) 
    {
        cout << "发现正品要购物了" << endl;
        //2. 去韩国买了个商品
        koreaShopping->buy(&it);

        //3 安检
        cout << "通过海光安检，带回祖国" << endl;
    }
    else
    {
        cout << "发现假货，不会购买" << endl;
    }
#endif

    Shopping* usaShopping = new USAShopping;
    Shopping* overseaProxy = new OverseasProxy(usaShopping);

    overseaProxy->buy(&it);


    return 0;
}

