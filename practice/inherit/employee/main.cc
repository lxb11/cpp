#include "Employee.h"
#include "Technician.h"
#include "Manager.h"
#include "SaleMan.h"
#include "SaleManager.h"

int main()
{
    Employee *person_array[] = {new Technician, new Manager, new SaleMan, new SaleManager};

    for(unsigned int i = 0; i < sizeof(person_array) / sizeof(person_array[0]); ++i)
    {
        person_array[i]->init();
        person_array[i]->getPay();
        person_array[i]->uplevel(1);
        person_array[i]->displayStatus();
    }

    for(unsigned int i = 0; i < sizeof(person_array) / sizeof(person_array[0]); ++i)
    {
        delete person_array[i];
    }
    return 0;
}

