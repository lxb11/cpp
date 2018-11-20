#include <iostream>
using namespace std;

/*
//5v电压
class V5
{
public:
    void useV5()
    {
        cout << "使用了5v电压" << endl;
    }
};
*/

class V5
{
public:
    virtual void useV5() = 0;
};

//目前只有220V的类
class V220
{
public:
    void useV220()
    {
        cout << "使用了220v电压" << endl;
    }
private:
};

//定义一个中间的适配器类
class Adapter:public V5
{
public:
    Adapter(V220* v220)
    {
        this->v220 = v220;
    }

    ~Adapter()
    {
        if(this->v220 != NULL)
        {
            delete this->v220;
        }
    }

    virtual void useV5()
    {
        cout << "适配器开始适配" << endl;
        v220->useV220();
    }
private:
    V220* v220;
};

class iPhone
{
public:
    iPhone(V5* v5)
    {
        this->v5 = v5;
    }

    ~iPhone()
    {
        if(this->v5 != NULL)
        {
            delete this->v5;
        }
    }

    //充电的方法
    void charge()
    {
        cout << "iPhone手机进行了充电" << endl;
        v5->useV5();
    }
private:
    V5* v5;
};

int main()
{
    iPhone* phone = new iPhone(new Adapter(new V220));
    phone->charge();
    return 0;
}

