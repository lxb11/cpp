#include <iostream>
using namespace std;

class Test
{
public:
    Test(int value)
    {
        this->value = value;
    }

    int getValue()
    {
        cout << "value  =" << this->value << endl;
        return this->value;
    }

    Test operator+(Test& another)
    {
        cout << "执行了+重载操作符" << endl;
        Test temp(this->value + another.value);
        return temp;
    }

    //重载&&操作符
    bool operator&&(Test& another)
    {
        cout << "执行了&&重载操作符" << endl;
        if(this->value && another.value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //重载||操作符
    bool operator||(Test& another)
    {
        cout << "执行了||重载操作符" << endl;
        if(this->value || another.value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    int value;
};

int main()
{
    Test t1(0);
    Test t2(20);

    if(t1.getValue() && (t1 + t2).getValue())//普通的&&会短路
    {
        cout << "if 进入成功" << endl;
    }

    cout << "重载的&&" << endl;

    //t1.operator&&(t1.operator + (t2))  我们重载的不会出现短路现象
    if(t1 && (t1 + t2))//Test && Test
    {
        cout << "if 进入成功" << endl;
    }

    if(t1 || (t1 + t2))
    {
        cout << "if || 进入成功" << endl;
    }

    return 0;
}

