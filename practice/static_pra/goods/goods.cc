#include "goods.h"

//一开始货物的重量时0
int Goods::total_weight = 0; 

Goods::Goods() 
{
    this->next = NULL;
    this->weight = 0;
    cout << "创建了一个货物重量是0的物品" << endl;
}

Goods::Goods(int weight)
{
    this->next = NULL;
    this->weight = weight;
    cout << "创建了一个货物重量是" << weight << "的物品" << endl;
    total_weight += weight;
}

//提供静态成员函数函数访问静态成员
int Goods::getTotal()
{
    return total_weight;
}


Goods::~Goods() 
{
    cout << "删除了货物重量是" << weight << endl;
    total_weight -= weight;
}


void buy(Goods* &head, int w)
{
    //创建一个新的货物
    //通过new在队上开辟空间，调用了Goods类的有参构造函数
    Goods *new_goods = new Goods(w);

    if(head == NULL)
    {
        //创建一个新的货物
        head = new_goods;
    }
    else
    {
        //如果head不为空，从head表头添加
        new_goods->next = head;
        head = new_goods;
    }
}

//出货的方法
void sale(Goods* &head)
{
    if(head == NULL)
    {
        cout << "仓库已经没有货物了" << endl;
    }
    Goods* temp = head;
    head = head->next;
    delete temp;
}
