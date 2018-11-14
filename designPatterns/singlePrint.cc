#include <iostream>
#include <string>
using namespace std;

class Printer
{
public:
    static Printer* getInstance()
    {
        return instance;
    }
    
    void print(string text)
    {
        cout << "打印的内容是" << text << endl;
        ++sequence;
        cout << "一共打印了" << sequence << "数据" << endl;
    }

    static int getCnt()
    {
        return sequence;
    }

private:
    Printer()
    {

    }

    //释放单例
    class Garbo
    {
    private:
        ~Garbo()
        {
            if(instance != NULL)
            {
                delete instance;
            }
        }
    };

    static Garbo garbo;//在静态区域开辟一个对象，garbo

    static int sequence;
    static Printer* instance;
};

int Printer::sequence = 0;
Printer* Printer::instance = new Printer;


int main()
{
    //员工1 获取
    Printer* p1 = Printer::getInstance();//获取到唯一的打印机实例
    p1->print("一份简历");

    Printer* p2 = Printer::getInstance();
    p2->print("lol皮肤");

    Printer* p3 = Printer::getInstance();
    p3->print("离职申请");


    return 0;
}

