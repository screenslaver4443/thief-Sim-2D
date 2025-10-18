#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee: Person {
    protected:
        int ID;
    public:
        int getID();
};

#endif
