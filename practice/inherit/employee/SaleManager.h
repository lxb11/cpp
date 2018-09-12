#pragma once
#include "SaleMan.h"
#include "Manager.h"

class SaleManager:public SaleMan, public Manager
{
public:
    SaleManager();
    ~SaleManager();

    //得到员工的薪水的方法
    virtual void getPay();

    //员工的升级方法
    virtual void uplevel(int addLevel);
    
    virtual void init();

private:

};

