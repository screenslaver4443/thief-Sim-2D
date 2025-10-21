#ifndef FOURTHLAYER_H
#define FOURTHLAYER_H

#include "ThirdLayer.h"
#include <string>

class StoreOwner: Employee {
    private:
        int suspicion;
        int level;
    public:
        int getSuspicion();
        void setSuspicion(int);
        int getLevel();
        void setLevel(int);
};

class Security: Employee {
    private:
        int suspicion;
        int level;
    public:
        int getSuspicion();
        void setSuspicion(int);
        int getLevel();
        void setLevel(int);
};

class PlayerThief: Criminal {
    private:
        int Health;
        int StolenGoods;
    public:
        void steal();
        void setStoleGoods(int);
        void attack();
        void takeDamage(int);
        void moveLeft();
        void moveRight();
        void jump();
};

class MafiaBoss: Criminal {
    private:
        int power;
        int satisfaction;
    public:
        int getPower();
        void setPower(int);
        int getSatisfaction();
        void setSatisfaction();
};

class AllyThief: Criminal {
    private: 
        int bond;
    public: 
        int getBond();
        void setBond(int);
};

#endif