#ifndef SECURITY_H
#define SECURITY_H

#include "Employee.h"

class Security : public Employee
{
private:
    bool isChasing = false;

public:
    Security();
    void chase(PlayerThief &player, float deltaTime);
};

#endif
