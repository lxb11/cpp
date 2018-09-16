#include <iostream>
using namespace std;

class A
{
public:
    virtual void func() 
    {
        cout << "A" << endl;

    }
    int a;

};

class B:public A
{
public:
    virtual void func() 
    {
        cout << "B" << endl;

    }
    int b;

};

class Animal
{
public:
    virtual void cry() = 0;

};

class Dog:public Animal
{
public:
    virtual void cry()
    {
        cout << "旺旺~~" << endl;
    }

    void doHome()
    {
        cout << "看家" << endl;
    }
};

class Cat:public Animal
{
public:
    virtual void cry()
    {
        cout << "喵喵~" << endl;
    }

    void doHome()
    {
        cout << "抓老鼠" << endl;
    }
};



int main()
{
    Animal* base = NULL;

    base = new Dog();
    base->cry();//此时父类指针指向Dog


    Dog* dog = new Dog();

    //用于将父类指针转换成子类
    dog = dynamic_cast<Dog*>(base);//转换之后 将父类指针转换成子类狗指针
        //但是由于父类指针此时指向的对象是猫
        //所以转换狗是失败的
        //如果转换失败则返回NULL

    if(dog != NULL)
    {
        cout << "转换成功" << endl;
        dog->cry();
        dog->doHome();
    }
    else
    {
        cout << "转换失败" << endl;
    }
    //dynamic_cast是将父类转换成子类，让老子变成儿子
    //让子类指针执行父类的对象

    Cat* pCat = dynamic_cast<Cat*>(base);//转换之后， 将父类指针转换成 子类猫指针
                                        //向下转换

    if(pCat != NULL)
    {
        pCat->cry();
        pCat->doHome();
    }

    base = new Dog();
    base->cry();

    cout << " ----- " << endl;

    A *ap = new A;
    ap->func();
    B *bp = dynamic_cast<B*>(ap);
    if (bp != NULL) 
    {
        cout << "转换成功" << endl;
        bp->func();
        cout << bp->b; //崩溃

    }
    else 
    {
        cout << "转换失败" << endl;

    }

    cout << " -----" << endl;

    return 0;
}

