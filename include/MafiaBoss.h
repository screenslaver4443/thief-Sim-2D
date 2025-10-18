#ifndef MAFIABOSS_H
#define MAFIABOSS_H

#include "Criminal.h"

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

#endif
