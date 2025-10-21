#ifndef PLAYERTHIEF_H
#define PLAYERTHIEF_H

#include "Criminal.h"

class PlayerThief: Criminal {
    private:
        int Health;
        int StolenGoods;
    public:
        void steal();
        void setStoleGoods(int stolenGoods);
        void attack();
        void takeDamage(int damage);
        void moveLeft();
        void moveRight();
        void jump();
};

#endif
