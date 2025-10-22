#ifndef MAFIABOSS_H
#define MAFIABOSS_H
// mafia boss will inherit from criminal and provide speed boost to player
// when touched

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
