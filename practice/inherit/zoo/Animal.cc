#include "Animal.h"


Animal::Animal()
{
    cout << "Animal()-----" << endl;
}

Animal::~Animal()
{
    cout <<"~Animal()-----" << endl;
}

void AnimalVoice(Animal& ap)
{
    cout << "动物开始乱叫啦" << endl;
    ap.voice();
    cout << "动物乱叫结束啦" << endl;
}
