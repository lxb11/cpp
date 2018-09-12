#pragma once
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal();
    virtual ~Animal();

    //纯虚函数
    virtual void voice() = 0;

private:

};

//架构函数
void AnimalVoice(Animal& ap);
