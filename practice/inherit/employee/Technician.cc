#include "Technician.h"

Technician::Technician()
{
    cout << "Technician()" << endl;
}
Technician::~Technician()
{
    cout << "~Technician" << endl;
}

//得到员工的薪水的方法
void Technician::getPay()
{
    cout << "请输入一个月工作了多少小时" << endl;
    cin >> this->workHour; 

    //计算工资
    this->salary = perHourMoney * workHour;
}

//员工的升级方法
void Technician::uplevel(int addLevel)
{
    this->level += addLevel;
}

void Technician::init()
{
    cout << "请输入技术人员的name" << endl;
    cin >> this->name;
    this->perHourMoney = 100; //技术人员每小时赚100
}
