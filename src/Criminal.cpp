// parent class to thr bad guys
#include "Criminal.h"

Criminal::Criminal()
{
    skill = 1;
    strength = 1;
}

int Criminal::getStrength()
{
    return strength;
}

void Criminal::setStrength(int s)
{
    strength = s;
}

int Criminal::getSkill()
{
    return skill;
}

void Criminal::setSkill(int s)
{
    skill = s;
}
