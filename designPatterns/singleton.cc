#include <iostream>
using namespace std;


/*
 *单例模式
 一是某个类只能有一个实例
 二是必须自行创建这个实例
 三是他必须自行向整个系统提供整个实例
 *
 *
 *单利模式的使用步骤
 a 构造函数私有化
 b 提供一个全局的静态方法（全局访问点）来获取单例对象
 c 在类中定义一个静态指针，指向本类变量的静态变量指针
 *
 *
 *
 * */



class Singleton
{
public:
    static Singleton* getinstance()//指向本类唯一实例的指针
    {
        return instance;
    }
private:
    //不让类的外部在创建实例
    Singleton()
    {


    }
    static Singleton* instance;//指向本类唯一实例的指针
};

//饿汉式---在编译期间就已经确定这个唯一的实例了
Singleton* Singleton::instance = new Singleton;//类的内部



class Singleton2
{
public:
    static Singleton2* getinstance()
    {
        if(instance == NULL)
        {
            instance = new Singleton2;
        }
            return instance;
    }
private:
    Singleton2()
    {

    }
    static Singleton2* instance;
};

//懒汉式---
Singleton2* Singleton2::instance = NULL;

int main()
{
    Singleton* s1 = Singleton::getinstance();
    Singleton* s2 = Singleton::getinstance();
    if(s1 == s2)
    {
        cout << "是一个单例" << endl;
    }
    else
    {
        cout << "不是一个单例" << endl;
    }

    Singleton2* s3 = Singleton2::getinstance();
    Singleton2* s4 = Singleton2::getinstance();
    if(s3 == s4)
    {
        cout << "是一个单例" << endl;
    }
    else
    {
        cout << "不是一个单例" << endl;
    }

    return 0;
}

