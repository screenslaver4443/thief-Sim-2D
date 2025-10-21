#ifndef HEALTHINDICATOR_H
#define HEALTHINDICATOR_H

#include "UI.h"



class HealthIndicator : UI {
 private:
  int health;

 public:
  HealthIndicator(int health);
  void setHealth(int health);
  int getHealth();
};

#endif
