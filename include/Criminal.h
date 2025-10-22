// parent class to thr bad guys
#ifndef CRIMINAL_H
#define CRIMINAL_H

#include "Person.h"

class Criminal : public Person
{
protected:
    int skill;
    int strength;

public:
    Criminal();
    virtual ~Criminal() = default;
    int getStrength();
    void setStrength(int);
    int getSkill();
    void setSkill(int);
};

#endif
