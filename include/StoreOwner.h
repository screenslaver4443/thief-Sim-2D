#ifndef STOREOWNER_H
#define STOREOWNER_H

#include "Employee.h"

class StoreOwner: Employee {
    private:
        int suspicion;
        int level;
    public:
        int getSuspicion();
        void setSuspicion(int);
        int getLevel();
        void setLevel(int);
};

#endif
