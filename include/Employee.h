#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee: Person {
    protected:
        int ID;
    public:
        Employee();
        Employee(int ID);
        int getID();
};

#endif
