#ifndef SECURITY_H
#define SECURITY_H

#include "Employee.h"

class Security: Employee {
    private:
        int suspicion;
        int level;
    public:
        Security(int suspicion, int level);
        int getSuspicion();
        void setSuspicion(int suspicion);
        int getLevel();
        void setLevel(int level);
};

#endif
