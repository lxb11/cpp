#include "SaleMan.h"
#include "Manager.h"
#include "SaleManager.h"

SaleManager::SaleManager()
{
    cout << "SaleManager()" << endl;
}

SaleManager::~SaleManager()
{
    cout << "~SaleManager" << endl;
}

//得到员工的薪水的方法
void SaleManager::getPay()
{
    cout << "请输入销售经理当前余额的销售额" << endl;
    cin >> this->saleAmount;

    //计算薪水
    this->salary = this->fixSalary + this->saleAmount * this->salePercent;

}

//员工的升级方法
void SaleManager::uplevel(int addLevel)
{
    this->level += addLevel;
}

void SaleManager::init()
{
    cout << "请输入销售经理的名字" << endl;
    cin >> this->name;

    this->fixSalary = 5000;
    this->salePercent = 0.05;

}
