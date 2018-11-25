#include <iostream>
#include <string>
#include <list>
using  namespace std;

//观察者，（监听者）
class Listenner
{
public:
    //老师来了，我该怎么办
    virtual void onTeacherComming() = 0;

    //学生干坏事的方法
    virtual void doBadthing() = 0;
};

//抽象的 被观察者（通知者）
class Notifier
{
public:
    //添加观察者的方法
    virtual void addListenner(Listenner* listenner) = 0;
    //删除观察者的方法
    virtual void delListenner(Listenner* listenner) = 0;
    
    //通知所有观察者的方法
    virtual void notify() = 0;
};

//具体地观察者
class Student:public Listenner
{
public:
    Student(string name, string badthing):_name(name),_badting(badthing){}
    
    //老师来了学生该怎么办O
    virtual void onTeacherComming()
    {
        cout << "学生" << _name << "发现班长给我的眼神，停止" << _badting << endl;
        cout << "改为写作业" << endl;

    }

    virtual void doBadthing()
    {
        cout << "学生" << _name << "正在干" << _badting << endl;

    }
private:
    string _name;
    string _badting;
};

//具体通知者
class Monitor:public Notifier
{
public:
    //添加观察者的方法
    virtual void addListenner(Listenner* listenner)
    {
        this->_l_list.push_back(listenner);

    }
    //删除观察者的方法
    virtual void delListenner(Listenner* listenner)
    {
        this->_l_list.remove(listenner);
    }
    
    //通知所有观察者的方法
    virtual void notify()
    {
        //广播消息，让每个学生都执行各自的重写的 onTeacherComming() 的方法
        for(list<Listenner*>::iterator it = _l_list.begin(); it != _l_list.end(); ++it)
        {
            (*it)->onTeacherComming();
        }

    }
private:
    list<Listenner*> _l_list;//班长手中所有的学生列表

};

int main()
{
    Listenner* s1 = new Student("张三", "抄作业");
    Listenner* s2 = new Student("李四", "打LOL");
    Listenner* s3 = new Student("王五", "看李四在打LOL");

    Notifier* bossXu = new Monitor;

    //将所有的学生列表告知通知者，好让通知者进行通知
    bossXu->addListenner(s1);
    bossXu->addListenner(s2);
    bossXu->addListenner(s3);

    cout << "教室一片和谐, 老师没有来" << endl;
    s1->doBadthing();
    s2->doBadthing();
    s3->doBadthing();

    cout << "班长突然发现老师来了，给学生发了个眼神" << endl;
    bossXu->notify();
    return 0;
}

