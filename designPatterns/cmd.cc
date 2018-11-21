#include <iostream>
#include <list>
using namespace std;

//系统的一个核心模块
class Doctor
{
public:
    //治疗眼睛的方法
    void treatEyes()
    {
        cout << "医生治疗了眼睛" << endl;
    }
    //治疗鼻子的方法
    void treatNose()
    {
        cout << "医生治疗了鼻子" << endl;
    }
private:

};

//定义一个抽象的病单
class Command
{
public:
    Command(Doctor* doctor):_doctor(doctor){}
    virtual ~Command()
    {
        if(this->_doctor != NULL)
        {
            delete this->_doctor;
            this->_doctor = NULL;
        }
    }

    virtual void treat() = 0;
    
protected:
    Doctor* _doctor;

};

//治疗眼睛的病单
class CommandEyes:public Command
{
public:
    CommandEyes(Doctor* doctor):Command(doctor){}
    //病单执行治疗的时候，实际上让医生治疗
    virtual void treat()
    {
        this->_doctor->treatEyes();
    }
};

//治疗鼻子的病单
class CommandNose:public Command
{
public:
    CommandNose(Doctor* doctor):Command(doctor){}
    //病单执行治疗的时候，实际上让医生治疗
    virtual void treat()
    {
        this->_doctor->treatNose();
    }
};

#if 0
//护士类
class Nurse
{
public:
    Nurse(Command* cmd):_cmd(cmd){}
    ~Nurse()
    {
        if(this->_cmd != NULL)
        {
            delete this->_cmd;
            this->_cmd = NULL;
        }
    }

    //下发病单的方法
    void notify()
    {
        this->_cmd->treat();
    }
private:
    Command* _cmd;
};
#endif

//护士长
class NurseBoss
{
public:
    NurseBoss()
    {
        this->m_list.clear();
    }
    ~NurseBoss()
    {
        this->m_list.clear();
    }
    void setCmd(Command* cmd)
    {
        this->m_list.push_back(cmd);
    }

    //下发手里所有病单的指令
    void notify()
    {
        for(list<Command*>::iterator it = m_list.begin(); it != m_list.end(); ++it)
        {
            (*it)->treat();
        }
    }
private:
    list<Command*> m_list;

};

int main()
{
#if 0
    Command* cmd1 = new CommandEyes(new Doctor);
    cmd1->treat();

    Command* cmd2 = new CommandNose(new Doctor);
    cmd2->treat();

    Nurse* nu = new Nurse(new CommandNose(new Doctor));
    nu->notify();
    Nurse* nu1 = new Nurse(new CommandNose(new Doctor));
    nu1->notify();
#endif

    NurseBoss* nuboss = new NurseBoss;
    Command* cmd1 = new CommandEyes(new Doctor);
    Command* cmd2 = new CommandNose(new Doctor);
    
    nuboss->setCmd(cmd1);
    nuboss->setCmd(cmd2);

    //将指令都给护士长
    nuboss->notify();

    return 0;
}

