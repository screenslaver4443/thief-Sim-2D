#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "PlayerThief.h"
#include <SFML/Graphics.hpp>

class Employee : public Person
{
private:
    float suspicion = 0.f;
    float suspicionTimer = 0.f;
    float suspicionRate = 1.f;
    int heartsRemaining = 3;
    float suspicionLimit = 10.f;

public:
    Employee();

    void update(float deltaTime, PlayerThief &player);
    void resetSuspicion();
    void setSuspicionRate(float r) { suspicionRate = r; }
};

#endif
