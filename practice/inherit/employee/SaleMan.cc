#include "SaleMan.h"

SaleMan ::SaleMan()
{
    cout << "请输入销售人员的姓名" << endl;
    cin >> this->name;

    this->salePercent = 0.04;//按4%提成
}

SaleMan:: ~SaleMan()
{
    cout << "~SaleMan" << endl;
}

 //得到员工的薪水的方法
 void SaleMan::getPay()
{
    cout << "请输入该员工本月的销售额" << endl;
    cin >> this->saleAmount;

    //计算薪水
    this->salary = this->saleAmount * this->salePercent;
}

 //员工的升级方法
 void SaleMan::uplevel(int addLevel)
{
    this->level += addLevel;
}

