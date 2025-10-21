#ifndef ALLYTHIEF_H
#define ALLYTHIEF_H

#include "Criminal.h"

class AllyThief : Criminal {
  private:
    int bond;
  public:
    AllyThief(int bond);
    int getBond();
    void setBond(int bond);
};

#endif
