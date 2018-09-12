#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
    Animal* ap = new Dog;
    AnimalVoice(*ap);
    delete ap;

    ap = new Cat;
    AnimalVoice(*ap);
    delete ap;

    return 0;
}

