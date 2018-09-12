#include "Employee.h"
#include "Technician.h"
#include "Manager.h"
#include "SaleMan.h"
#include "SaleManager.h"

int main()
{
    Employee *person = new SaleManager;

    person->uplevel(1);
    person->getPay();
    person->displayStatus();
    
    delete person;


    return 0;
}

