#ifndef MAFIABOSS_H
#define MAFIABOSS_H

#include "Security.h"
#include "Criminal.h"

class MafiaBoss : public Criminal
{
private:
    bool active;

public:
    MafiaBoss();
    void update(Security &security, PlayerThief &player, float deltaTime);
    void activate() { active = true; }
};

#endif
