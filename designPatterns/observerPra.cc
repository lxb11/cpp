#include <iostream>
#include <string>
#include <list>
using namespace std;

class Notifier;
//抽象的观察者
class Listenner
{
public:
    //当朋友被揍了我该怎么办
    virtual void onFriendBeFight(Listenner* one, Listenner* another) = 0;
    virtual void fighting(Listenner* another, Notifier* notifier) = 0;
    virtual string getName() = 0;
    virtual string getParty() = 0;
};

//抽象的通知者
class Notifier
{
public:
    //添加观察者
    virtual void addListenner(Listenner* listen) = 0;
    //删除观察者
    virtual void delListenner(Listenner* listen) = 0;
    
    //通知观察者
    virtual void notify(Listenner* one, Listenner* another) = 0;
};

//武林中的人物
class Hero:public Listenner
{
public:
    Hero(string name, string party):_name(name),_party(party){}

    //当我发现一个消息之后我该怎么办
    virtual void onFriendBeFight(Listenner* one, Listenner* another)
    {
        if(another->getName() != this->_name && one->getName() != this->_name)
        {
            //不是当事人，需要判断大人的party，和被打的party是不是我自己哥们
            if(one->getParty() == this->_party)
            {
                cout << _name << "发现自己认把别人揍了，笑了，拍手叫好" << endl;
            }
            else if(another->getParty() == this->_party)
            {
                cout << _name << "发现自己人被别人揍了，出手援救" << endl;
            }
            else
            {
                cout << "默默地观看" << endl;
            }
        }
    }

    //揍人的方法
    virtual void fighting(Listenner* another, Notifier* notifier)
    {
        cout << this->_name << "[" << this->_party << "]" << "把"
            << another->getName() << "[" << another->getParty() << "]" << "给揍了" << endl;

        //走完之后，应该让百晓生知道，应该调用百晓生的notify方法
        notifier->notify(this, another);
    }
    virtual string getName()
    {
        return this->_name;
    }
    virtual string getParty()
    {
        return this->_party;
    }
    
private:
    string _name;
    string _party;
};

class Baixiao:public Notifier
{
public:
    //添加观察者
    virtual void addListenner(Listenner* listen)
    {
        this->_l_list.push_back(listen);
    }
    //删除观察者
    virtual void delListenner(Listenner* listen)
    {
        this->_l_list.remove(listen);
    }
    
    //通知观察者
    virtual void notify(Listenner* one, Listenner* another)
    {
        for(list<Listenner*>::iterator it = _l_list.begin(); it != _l_list.end(); ++it)
        {
            (*it)->onFriendBeFight(one, another);
        }
    }
private:
    //拥有所有武林人士的名单
    list<Listenner*> _l_list;
};


int main()
{
    Listenner* hong7 = new Hero("洪七公", "丐帮");
    Listenner* huangrong = new Hero("黄蓉", "丐帮");
    Listenner* wuyazi = new Hero("无崖子", "逍遥派");
    Listenner* tonglao = new Hero("天寒童姥", "逍遥派");

    //创建一个百晓生
    Notifier* baixiao = new Baixiao;
    
    //百晓生 收集全部的武林人士名单
    baixiao->addListenner(hong7);
    baixiao->addListenner(huangrong);
    baixiao->addListenner(wuyazi);
    baixiao->addListenner(tonglao);
    
    //以上初始化完毕
    hong7->fighting(wuyazi, baixiao);

    cout << "------" << endl;
    tonglao->fighting(hong7, baixiao);

    return 0;
}

