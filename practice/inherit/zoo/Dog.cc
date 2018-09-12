#include "Animal.h"
#include "Dog.h"

Dog::Dog()
{
    cout << "~Dog()" << endl;
}

Dog::~Dog()
{
    cout << "~Dog()" << endl;
}

void Dog::voice()
{
    
    cout << "wang wang -----" << endl;
}



