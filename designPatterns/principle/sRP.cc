#include <iostream>
using namespace std;


#if 0
class Clothes
{
public:
    void shopping()
    {
        cout << "shoping style" << endl;
    }
    void working()
    {
        cout << "working style" << endl;
    }
};
#endif 

/*
 单一职责原则
 类的职责单一，对外只提供一种功能，而引起类变化的原因都应该有一个
 */

class ClothesShoping
{
public:
    void shopping()
    {
        cout << "shoping style" << endl;
    }
};

class ClothesWorking
{
public:
    void working()
    {
        cout << "working style" << endl;
    }
};

int main()
{
    ClothesShoping cs;
    cs.shopping();
    ClothesWorking cw;
    cw.working();
    return 0;
}

