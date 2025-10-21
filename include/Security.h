#ifndef SECURITY_H
#define SECURITY_H

#include "Employee.h"

class Security : public Employee
{
public:
    Security();
    void chase(PlayerThief &player);
};

#endif
