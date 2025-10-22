#ifndef MAFIABOSS_H
#define MAFIABOSS_H

#include "Security.h"

class MafiaBoss : public Person
{
private:
    bool active;

public:
    MafiaBoss();
    void update(Security &security, PlayerThief &player, float deltaTime);
    void activate() { active = true; }
};

#endif
