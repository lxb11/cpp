#pragma once
#include <iostream>
using namespace std;

class Goods
{
public:
    Goods();
    Goods(int weight);
    //提供静态成员函数函数访问静态成员
    static int getTotal();
    //给货物类变成一个链表的节点
    Goods* next;
    ~Goods();
private:
    int weight;//货物的重量
    static int total_weight;//所有货物的总重量
};


void buy(Goods* &head, int w);
void sale(Goods* &head);
