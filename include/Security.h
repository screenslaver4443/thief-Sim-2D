#ifndef SECURITY_H
#define SECURITY_H
// Security will walk to player at half player speed, and
// cause gameover if touched

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
