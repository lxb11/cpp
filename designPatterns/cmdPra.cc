#include <iostream>
#include <list>
using namespace std;

class Cooker
{
public:
    //烤串
    void makeChuaner()
    {
        cout << "烤串师傅进行了烤串" << endl;
    }
    //烤鸡翅
    void makeChicken()
    {
        cout << "烤串师傅进行了烤鸡翅" << endl;
    }
};

//烤串的菜单
class Command
{
public:
    Command(Cooker* cooker):_cooker(cooker){}
    ~Command()
    {
        if(this->_cooker != NULL)
        {
            delete this->_cooker;
            this->_cooker = NULL;
        }
    }
    //菜单让最终的执行者干活的方法
    virtual void execute() = 0;
protected:
    Cooker* _cooker;
};

//烤串的菜单
class CommandChuaner:public Command
{
public:
    CommandChuaner(Cooker* cooker):Command(cooker){}
    virtual void execute()
    {
        //命令 最终让执行者干的工作
        this->_cooker->makeChuaner();
    }
};
//烤鸡翅的菜单
class CommandChicken:public Command
{
public:
    CommandChicken(Cooker* cooker):Command(cooker){}
    virtual void execute()
    {
        this->_cooker->makeChicken();
    }
};

//管理所有命令的一个模块
//服务员mm
class Waitress
{
public:
    //给服务员添加菜单的方法
    void setCmd(Command* cmd)
    {
        this->_cmdList.push_back(cmd);
    }
    void notify()
    {
        list<Command*>::iterator it = _cmdList.begin();
        for(; it != _cmdList.end(); ++it)
        {
            (*it)->execute();//在此发生多态
        }
    }
private:
    list<Command*> _cmdList;
};


int main()
{
    Waitress* mm = new Waitress;
    Command* chuaner = new CommandChuaner(new Cooker);
    Command* chicken = new CommandChicken(new Cooker);

    //把订单都给服务员
    mm->setCmd(chuaner);
    mm->setCmd(chicken);

    //让服务员下单，最终让师傅干活
    mm->notify();
    

    return 0;
}

