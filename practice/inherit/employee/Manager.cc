#include "Employee.h"
#include "Manager.h"

Manager::Manager()
{
    cout << "请输入经理的姓名" << endl;
    cin >> this->name;

    //经历的固定薪水
    this->fixSalary = 8000;

}

Manager::~Manager()
{
    cout << "~Manager()" << endl;
}

//得到员工的薪水的方法
void Manager::getPay()
{
    //计算经理的薪资
    this->salary = fixSalary;
}

//员工的升级方法
void Manager::uplevel(int addLevel)
{
    this->level += addLevel;

}

