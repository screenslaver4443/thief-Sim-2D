#ifndef CRIMINAL_H
#define CRIMINAL_H

#include "Person.h"

class Criminal: Person {
    protected:
        int skill;
        int strength;
    public:
        int getStrength();
        void setStrength(int);
        int getSkill();
        void setSkill(int);
};

#endif
