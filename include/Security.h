#ifndef SECURITY_H
#define SECURITY_H

#include "Employee.h"

class Security: Employee {
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
