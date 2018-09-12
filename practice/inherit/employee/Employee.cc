#include "Employee.h"

//初始化静态成员
int Employee::startnum = 1000;//静态的编号计数


//所有抽象类的子类在构造函数的时候，都会调用父类构造
Employee::Employee()
{
    this->level = 1;
    this->salary = 0.0;
    this->id = startnum++;

}

Employee::~Employee()
{
    cout << "~Employee" << endl;
}

void Employee::displayStatus()
{
    cout << "----员工信息-----" << endl;
    cout << "姓名" << this->name << endl;
    cout << "级别" << this->level << endl;
    cout << "编号" << this->id << endl;
    cout << "当月的薪水" << this->salary << endl;
}
