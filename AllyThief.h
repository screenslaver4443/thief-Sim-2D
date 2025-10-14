#ifndef ALLYTHIEF_H
#define ALLYTHIEF_H

#include "Criminal.h"

class AllyThief: Criminal {
    private: 
        int bond;
    public: 
        int getBond();
        void setBond(int);
};

#endif
